![logo](../git/img/Git-logo.svg) [](logo-id)

# Git[](title-id)

### Inhoud[](toc-id)

- [Git](#git)
    - [Inhoud](#inhoud)
  - [Version Control System](#version-control-system)
  - [Alternatives to Git](#alternatives-to-git)
  - [Distributed versus centralized VCS](#distributed-versus-centralized-vcs)
  - [Git as a service](#git-as-a-service)
  - [Git from the command line](#git-from-the-command-line)
  - [Using Git](#using-git)
    - [Creating a repository](#creating-a-repository)
    - [Clone versus Fork](#clone-versus-fork)
    - [Basic workflow](#basic-workflow)
  - [Branching](#branching)
    - [Branching strategies](#branching-strategies)
    - [Branch how?](#branch-how)
    - [Branch 'Workflow'](#branch-workflow)
  - [Pull requests](#pull-requests)
  - [Git Commands](#git-commands)
    - [status](#status)
    - [config](#config)
    - [branch](#branch)
    - [stage, commit en merge](#stage-commit-en-merge)
  - [Workflow for trusted team](#workflow-for-trusted-team)
  - [Workflow for unknown contributors](#workflow-for-unknown-contributors)
  - [Git recommended workflow](#git-recommended-workflow)
  - [Referenties](#referenties)

---

**v0.1.0 [](version-id)** Git start document door HU IICT[](author-id).

---

## Version Control System

VCS is an abbreviation for Version Control System. A VCS is a tool that saves the changes to files in a local and/or remote repository. The benefit of using a VCS is the clear development history – at any point in time it is possible to see who did what and what happened since then. This clear development history makes it easier to locate bugs and roll back to stable versions. 

## Alternatives to Git

Are there any alternatives to using a VCS? Not really – one could use local backups on (removable) hard drives, but this makes working together much harder. Git is the most popular VCS worldwide, mostly because of its ease of use and speed – because you work locally you’re not as limited by network speed, there is no single point of failure as with centralized VCS(SVN) and git is available offline.

Alternatives to Git include Mercurial and SVN, but only about 16.1% of developers use SVN, and only 3.6% use Mercurial while 80-90% of developers use Git: [https://insights.stackoverflow.com/survey/2021#most-loved-dreaded-and-wanted-tools-tech-love-dread](https://insights.stackoverflow.com/survey/2021#most-loved-dreaded-and-wanted-tools-tech-love-dread). 

Another important thing to note with these statistics is that many developers don't use just one system - they will often use different systems profesionally than personally.

## Distributed versus centralized VCS

Git is a distributed VCS, meaning that you always have a working local repository in addition to a central remote. Centralized VCS only have a remote, so any ‘commits’ you make are sent directly to the remote. 

## Git versus GitHub: Git as a service

GitHub and Git are often used interchangably, but GitHub ‘merely’ hosts Git as a service. There are alternative hosts, such as GitLab, BitBucket, Sourceforge or hosting your own, but GitHub is the most popular provider. However, its market share has decreased a little ever since it got taken over by Microsoft.

If you decide to use a different host (although we recommend GitHub at this point in time) it is important to note that Git will work the same for every host you choose. It is the host's specific infrastructure and functionality that can be different, but the underlying Git functionality remains the same.

## Git from the command line

You can use Git integrated through your IDE or with a GUI, but this presents several problems; they may be linked to specific languages (JetBrains), may not always be available (problems with software) and as a developer you're never fully sure what actually happens when using these tools.

As a software developer it’s important to select the right tools for the job, but Git through command line is always a good tool to have: you can always use it, you have full control and you are not limited to a specific environment.

Example; 1st year students have learned to use Git through JetBrains IDEs, but not manually. For a project they did they had to work with the Arduino IDE, which does not have a native git integration. They said they kept copy+pasting code from Arduino IDE to Clion in order to use the Git integration.

## Using Git

### Creating a repository

There are a few ways of making a new repository. The easiest is by making one on GitHub, or your host of choice, and cloning that to a local repository. This is easiest, because it allows you to initiate with a readme, a gitignore and a license. It also makes it easy for your clone of this repo to find the remote when making your first commit from your local repository. You can then simply clone the remote to make a local copy. It is also possible to initiate a new repo locally and then set its remote using `git remote add <REPO NAME> <REPO SSH/URL>` . This feels like more work though, and if you want a remote anyway it’s easier to start by making the remote.

### Clone versus Fork

Cloning and Forking both create copies of a repository, but with different intents. Forking makes an unlinked remote copy, whereas cloning makes a linked local copy. In a forked repo you can contribute changes without affecting the original (this is where the term unlinked comes from), but a clone can’t do this - because the repositories are linked any pushes will also update the remote. You can, of course, combine the two -> Fork first to make your own remote (unlinked) copy, and then clone to work on the project locally.

### Basic workflow

`git status`: Shows tracked files that have changed and new files that aren’t tracked yet. Additionally; `git diff``: Shows changes within files

`git log --all --graph`: shows the commit history in the form of a graph

`git add`: Allows to add new files to the staging area; can be new files or tracked files that have changed


`git add` has a lot of flags/commands you can use to make using it easier (such as `git add .` or `git add -a`), but usually it’s neater to use filenames directly -> `git add <filename1> <filename2>`: this way you keep full control of what happens.

    https://stackoverflow.com/a/26039014

    Using these flags is generally discouraged, but if you DO use them at least make sure you know what they do exactly.

`git restore`: Allows for removal of staged files from staging area -> `git restore <filename>`

`git commit`: ‘Saves’ staging area to local repository. Use the –m flag to add a commit message. Another –m can be used for a more detailed description -> `git commit –m “COMMIT MESSAGE” –m “MORE DETAILS”`. The first –m is ‘required’ (not adding it opens a text editor to type it instead), the second is optional.

There is also `git push` to push your commits to the linked remote repo, but this is further explained in the branching segment.

## Branching

A branch is a copy of the main codebase, where one can introduce changes without changing the main codebase. These are used so developers can work on new features, fixes, etc. in parallel without changing the main codebase until whatever is worked on in the branch is complete. Properly using branches prevents merge conflicts.

![branch](../git/img/Revision_controlled_project_visualization-2010-24-02.svg)

Merge conflicts should be avoided if possible. They occur when conflicting versions of files exist when either pulling to your local repo or pushing to the remote. A proper Git Workflow with proper use of a Branching Strategy prevents most merge conflicts.

### Branching strategies

There are a few different strategies development teams use for branching, but the most common is branching based on features. In this strategy, a team usually starts off with a main branch – this is the release branch. This branch only contains working code ready for release. From the main branch a development branch is created – this is where complete code is ‘staged’ until it is ready to be released. From this development branch developers create new branches for each new feature, including potential branches for bug fixes etc. If an agile project is properly set up (task division etc.), this is very easy to do. 

### Branch how?

Making new branches or switching to existing branches can be done using the `git checkout` commands. Adding the `-b` flag allows for making a new branch as such; `git checkout –b “new_branch_name”` (quotes aren’t necessary, but some developers prefer using them). If you leave out the –b flag you change to an existing branch instead -> `git checkout “dev”` would switch to the ‘dev’ branch.

Do note that, alternatively, you can use the `git branch "new_branch_name"` command to make a new branch. This accomplishes the same as `git checkout`, but leaves you on your current branch. You can then use `git switch "new_branch_name"` to switch to that branch (similar to checkout).

### Branch 'Workflow'

Working with branches introduces a few new commands: 

```bash
git checkout 
# Checkout is used for switching branches or making a new one. The –b flag allows for making a new branch, while leaving that flag unchecked switches to a different branch; `git checkout (-b) “branch_name”`
```
```bash
git pull 
# Pulls changes from the remote to your local repository. If you use this in a specific branch only the changes from the remote to that branch are pulled. For example, if the dev branch has been changed but you pull a different feature branch, you don’t pull the changes to the dev branch.
```
```bash
git push 
# Pushes your local commits to the branch you are in to the corresponding branch on the remote. Similar to pull, this only works for the specific branch you are on.
```
```bash
git merge “other” 
# Merges ‘other’ into the branch you are currently in. Merging can create merge conflicts, so using it properly requires a merging strategy.
```
 
### Merging workflow

First, make sure the branch you want to merge into is up to date by switching to that branch and pulling it. This branch is called the destination.
```bash
git checkout "destination"
git pull
```

Then move back to the branch you want to merge (origin) and merge the destination branch to your origin. 

```bash
git checkout "origin"
git merge "destination"
```

If merge conflicts arise, fix them and repeat from the top.

If no merge conflicts arise (anymore), you can push your local changes with `git push`

Switch to your destination folder and merge the branch you want to merge into destination, push changes.

```bash
git checkout "destination"
git merge "origin"
git push
```

## Pull requests

Pull requests are a [GitHub](https://www.GitHub.com) feature, not Git. They allow you to ask if a branch can be merged into a different branch, giving the opportunity for a code review. This is usually done in order to allow feature branches to be merged into dev, or even to merge dev into main.

## Configureren
Vooraf eenmalig instellen:
```bash
# VsCode instellen als default editor:
git config --global core.editor "code --wait"

# Fast Forward merging uitzetten:
git config --global merge.ff false
```

### branch

```bash
# Nieuwe branch maken
git branch myBranch

# Of bestaande branch van remote halen:
git pull myBranch

# Switchen naar de nieuwe branch:
git switch myBranch
```

### stage, commit en merge

... Coderen, files veranderen, aanmaken  ....

```bash
# Alle veranderingen stagen
git stage .

# Je kunt ook files per stuk stagen of unstagen:
git stage file1
git unstage file1

# committen:
git commit -m "korte beschrijving" "evt lange beschrijving"

# voor het geval myBranch op de remote staat, nog een keer pullen:
git pull myBranch

# ook de master, zodat je daar de laatste versie van hebt
git pull master

# dan die laatste master naar je myBranch (waar je nog bent) mergen:
git merge master

# dan myBranch terug mergen naar de master (als je de branch op de remote wilt mergen):
git switch master     (eerst naar de master branch gaan)
git merge myBranch    (myBranch naar de master branch mergen)

git push master

# check nog een laatste keer dat alles gelukt is met git status en git log.
# als dat het geval is, is de branch gelijk aan de head en de master, en kan hij verwijderd worden:
git branch -d myBranch

# als hij ook remote stond, ook:
git push origin --delete myBranch
```

## Workflow for trusted team
![Workflow for trusted team](../git/img/GIT_Werkwijzen-Vertrouwd.drawio.svg)

## Workflow for unknown contributors
![Workflow_for_unknown_contributors](../git/img/GIT_Werkwijzen-OpenSource.drawio.svg)

## Git recommended workflow
![Workflow_for_unknown_contributors](../git/img/GIT_Werkwijzen-Koninklijke%20Weg.drawio.svg)

## Referenties

- Git on Wikipedia (<https://en.wikipedia.org/wiki/Git>)
- GitGud (<https://github.com/Druyv/GitGud/tree/main>)
- Git (<https://git-scm.com/>)