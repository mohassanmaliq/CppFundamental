# Git commands reference
# Every line is a comment, so nothing here runs.

# --- Setup ---
# git config --global user.name "Your Name"      set your name
# git config --global user.email "you@example.com"   set your email
# git config --global init.defaultBranch main    default branch name for new repos
# git config --list                              show all settings

# --- Start a repository ---
# git init                                       create a new repo in this folder
# git clone <url>                                copy a remote repo
# git clone <url> <folder>                       clone into a named folder

# --- Check state ---
# git status                                     show changed and staged files
# git log                                        full commit history
# git log --oneline                              one line per commit
# git log --oneline --graph --all                branch graph
# git diff                                       unstaged changes
# git diff --staged                              staged changes
# git show <commit>                              details of one commit

# --- Stage and commit ---
# git add <file>                                 stage one file
# git add .                                      stage everything
# git add -p                                     stage changes piece by piece
# git commit -m "message"                        commit staged changes
# git commit -am "message"                       stage tracked files and commit
# git commit --amend                             edit the last commit

# --- Undo changes ---
# git restore <file>                             discard changes in a file
# git restore --staged <file>                    unstage a file
# git reset --soft HEAD~1                        undo last commit, keep changes staged
# git reset --hard HEAD~1                        undo last commit, delete changes
# git revert <commit>                            new commit that reverses a commit
# git clean -fd                                  delete untracked files and folders

# --- Branches ---
# git branch                                     list branches
# git branch <name>                              create a branch
# git branch -d <name>                           delete a merged branch
# git branch -D <name>                           force delete a branch
# git branch -m <new-name>                       rename current branch
# git switch <name>                              move to a branch
# git switch -c <name>                           create and move to a branch
# git checkout <name>                            older way to switch branches
# git checkout -b <name>                         older way to create and switch

# --- Merge and rebase ---
# git merge <branch>                             merge a branch into the current one
# git merge --abort                              cancel a merge in progress
# git rebase <branch>                            replay your commits on top of a branch
# git rebase -i HEAD~3                           edit the last 3 commits
# git rebase --continue                          continue after fixing conflicts
# git rebase --abort                             cancel a rebase
# git cherry-pick <commit>                       copy one commit onto the current branch

# --- Remotes ---
# git remote -v                                  list remotes
# git remote add origin <url>                    add a remote
# git remote set-url origin <url>                change a remote's url
# git fetch                                      download changes without merging
# git pull                                       fetch and merge
# git pull --rebase                              fetch and rebase
# git push                                       upload commits
# git push -u origin <branch>                    push and set upstream
# git push origin --delete <branch>              delete a remote branch

# --- Stash ---
# git stash                                      save changes and clean the working tree
# git stash -u                                   include untracked files
# git stash list                                 list stashes
# git stash pop                                  apply latest stash and remove it
# git stash apply                                apply latest stash and keep it
# git stash drop                                 delete latest stash
# git stash clear                                delete all stashes

# --- Tags ---
# git tag                                        list tags
# git tag <name>                                 create a tag
# git tag -a <name> -m "message"                 create an annotated tag
# git push origin <name>                         push one tag
# git push origin --tags                         push all tags
# git tag -d <name>                              delete a local tag

# --- Inspect and search ---
# git blame <file>                               who changed each line
# git grep "text"                                search tracked files
# git log -S "text"                              commits that added or removed text
# git log --author="name"                        commits by one author
# git log -- <file>                              history of one file
# git shortlog -sn                               commit count per author

# --- Remove and rename files ---
# git rm <file>                                  delete a file and stage it
# git rm --cached <file>                         stop tracking, keep the file
# git mv <old> <new>                             rename or move a file

# --- Recovery ---
# git reflog                                     history of where HEAD has been
# git reset --hard <commit-from-reflog>          go back to a commit found in reflog
# git checkout <commit> -- <file>                restore a file from a commit