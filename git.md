author = “Xinhong Wu”

# 🛠 Git 核心要点与 Xcode 联动手册

这份手册记录了从 C++ 代码管理到 GitHub 联动的核心逻辑，涵盖了遇到的所有典型坑位。

---

## 1. Git 的三个逻辑层级

理解 Git 的核心在于明白数据是如何流动的：

* **工作区 (Working Directory)**：你正在修改的代码文件（你的房间）。
* **暂存区 (Staging Area/Index)**：准备提交的“快递纸箱”。
* **本地仓库 (Local Repo)**：已经封箱存盘的记录（你的个人档案库）。
* **远程仓库 (Remote Repo/GitHub)**：发往云端的备份（共享的档案库）。

---

## 2. 常用操作指令与 Xcode 对应

| 动作 | 含义 | Xcode 快捷键 / 位置 | 终端命令 |
| --- | --- | --- | --- |
| **Stage** | 将改动放入暂存区 | 在 Commit 窗口勾选文件左侧框 | `git add <file>` |
| **Commit** | 存盘，记录当前快照 | `Cmd + Opt + C` | `git commit -m "msg"` |
| **Pull** | 拉取云端更新并合并 | `Source Control` -> `Pull` | `git pull` |
| **Push** | 将本地存盘推往云端 | `Source Control` -> `Push` | `git push` |
| **Amend** | **修订**最后一次提交 | Commit 窗口勾选 **Amend** | `git commit --amend` |

---

## 3. 核心坑位深度解析

### ⚠️ "No staged changes"

* **原因**：改了代码，但没勾选文件（没放进快递盒）。
* **解决**：在 Xcode Commit 界面勾选文件名左边的复选框。

### ⚠️ "The local repository is out of date"

* **原因**：云端有你本地没有的提交。这通常发生在：
1. 你在 GitHub 网页改了代码。
2. 你在另一台设备提交了代码。
3. **最常见**：你对已经 Push 过的代码执行了 `Amend`（导致历史分叉）。


* **解决**：先 `Pull` 同步；
若由于 `Amend` 导致，则需 `Force Push`。
or try pull then choose the right version of file.then stage、commit、push.

---

## 4. `Amend` 的“后悔药”属性与禁忌

* **作用**：合并当前的改动到上一次 Commit 中，不产生冗余记录，保持历史整洁。
* **禁忌**：**绝对不要 Amend 已经 Push 过的代码！**
* 因为 `Amend` 会销毁旧 Commit 并创建 ID 全新的新 Commit。
* 如果已 Push，会导致本地与云端历史脱节（分叉）。




---

## 5. Xcode 中的“核武器”：Force Push（强推）

当你因为 `Amend` 导致无法 Push 时，可以用强推覆盖云端历史。

### 如何在 Xcode 开启：

1. `Settings` -> `Source Control` -> `Git`。
2. 勾选 **"Show Force Push option"**。
3. 在 Push 界面点击下拉小箭头，选择 **Force Push**。

### 终端命令：

```bash
git push -f origin main

```

---

## 6. 工程化建议：`.gitignore`

* **作用**：防止无关文件（如编译产生的 `.o`、可执行文件、Mac 的 `.DS_Store`）进入仓库。
* **好处**：保持仓库轻量，避免不必要的冲突。

---

## 💡 程序员的线性逻辑思维

* **#include**：是代码层面的“接口声明”。
* **Commit**：是逻辑层面的“状态保存”。
* **Push**：是空间层面的“多端对齐”。
* **Amend**：是时间层面的“历史重写”。

---

**你可以把这个 `.md` 文件放到你的 GitHub 仓库里，作为你的第一份 Git 学习文档！**
