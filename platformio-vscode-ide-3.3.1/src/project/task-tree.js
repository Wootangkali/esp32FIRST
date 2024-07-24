/**
 * Copyright (c) 2017-present PlatformIO <contact@platformio.org>
 * All rights reserved.
 *
 * This source code is licensed under the license found in the LICENSE file in
 * the root directory of this source tree.
 */

import * as vscode from 'vscode';

export default class ProjectTasksTreeProvider {
  static DEFAULT_ENV_NAME = 'Default';

  constructor(id, envs, tasks, selectedEnv = undefined, multiEnvExplorer = false) {
    this.id = id;
    this.envs = envs;
    this.tasks = tasks;
    this.selectedEnv = selectedEnv;
    this.multiEnvProject = this.envs.length > 1;
    this.multiEnvExplorer = multiEnvExplorer;
  }

  getEnvTasks(env = undefined, group = undefined) {
    const cmpGroup = (task) => {
      if (!group) {
        return true;
      }
      return task.group === group;
    };
    const result = this.tasks.filter((task) => cmpGroup(task) && task.coreEnv === env);
    // merge default/env-independent tasks
    if (env) {
      result.push(
        ...this.tasks.filter(
          (task) =>
            cmpGroup(task) &&
            env !== ProjectTasksTreeProvider.DEFAULT_ENV_NAME &&
            !task.multienv
        )
      );
    }
    return result;
  }

  getTreeItem(item) {
    return item instanceof vscode.TreeItem ? item : this.taskToTreeItem(item);
  }

  taskToTreeItem(task) {
    const treeItem = new vscode.TreeItem(task.name);
    treeItem.iconPath = new vscode.ThemeIcon('circle-outline');
    treeItem.tooltip = task.title;
    treeItem.command = {
      title: task.title,
      command: 'platformio-ide._runProjectTask',
      arguments: [task],
    };
    if (!task.coreEnv && task.multienv && this.multiEnvProject) {
      treeItem.label += ' All';
    }
    return treeItem;
  }

  getChildren(element) {
    if (element && element.group) {
      return this.getEnvTasks(element.env, element.group);
    } else if (element) {
      return this.getEnvChildren(element.env);
    } else if (this.selectedEnv && !this.multiEnvExplorer) {
      return this.getEnvChildren(this.selectedEnv);
    }
    return this.getRootChildren();
  }

  getRootChildren() {
    const result = [];
    for (const env of [undefined, ...this.envs]) {
      const treeItem = new vscode.TreeItem(
        env || ProjectTasksTreeProvider.DEFAULT_ENV_NAME,
        env && (env === this.selectedEnv || !this.multiEnvProject)
          ? vscode.TreeItemCollapsibleState.Expanded
          : vscode.TreeItemCollapsibleState.Collapsed
      );
      treeItem.id = `${this.id}-${env}`;
      treeItem.env = env;
      treeItem.iconPath = new vscode.ThemeIcon('root-folder');
      result.push(treeItem);
    }
    return result;
  }

  getEnvChildren(env) {
    const envTasks = this.getEnvTasks(env);
    if (!envTasks.length) {
      return [new vscode.TreeItem('Loading...')];
    }
    const result = envTasks.filter((task) => !task.group);
    // root groups
    for (const group of this.getTaskGroups(envTasks)) {
      const element = new vscode.TreeItem(
        group,
        ['General', 'Platform'].includes(group)
          ? vscode.TreeItemCollapsibleState.Expanded
          : vscode.TreeItemCollapsibleState.Collapsed
      );
      element.env = env;
      element.group = group;
      element.iconPath = vscode.ThemeIcon.Folder;
      result.push(element);
    }
    return result;
  }

  getTaskGroups(tasks) {
    const result = ['General'];
    const candidates = tasks.filter((task) => task.group).map((task) => task.group);
    // reorder
    if (candidates.includes('Platform')) {
      result.push('Platform');
    }
    for (const group of candidates) {
      if (!result.includes(group)) {
        result.push(group);
      }
    }
    return result;
  }
}
