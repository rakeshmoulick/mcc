# Some commands for github 
# -------------------------------------
# 1. Add files to github repository from the computer
<!-- When uploading to github from the working directory of a computer: Go to the path of the working directory via the terminal and type the following sequentially or as required -->
<!-- -------------------------------------------- -->
<!-- To check what has been modified in the directory or is there any new uncomitted things in the directory-->
git status 
<!-- -------------------------------------------- -->
<!-- Add all the new changes to be committed to github -->
git add .
<!-- -------------------------------------------- -->
<!-- Commit with a message -->
git commit -m "your message"
<!-- -------------------------------------------- -->
<!-- push the committed objects and files to github main branch -->
git push origin main
<!-- While you attempt to push to Github, it will ask for username and password. However, the password should be the one you generated as PAT (Personal Access Token), and not the usual login password -->


# Pull from github to the working computer (always begin working after a pull)
<!-- -------------------------------------------- -->
git status                           # Verify clean workspace
git checkout main                    # Move to main branch
git fetch --all --prune              # Gather GitHub data updates
git pull --rebase origin main        # Neatly pull updates
git checkout -b feature/my-new-task  # Create your workspace branch
<!-- -------------------------------------------- -->


# Delete files in the github repository (via terminal)
<!-- change directory path to the specific working directory -->
cd path/to/your/repository
<!-- -------------------------------------------- -->
<!-- If you want to delete the files from both github repository and the local working directory follow: -->
git rm filename.ext
<!-- -------------------------------------------- -->
<!-- If you only want to untrack the file from GitHub but keep the physical file on your computer, run the following instead -->
git rm --cached filename.ext
<!-- -------------------------------------------- -->
<!-- Commit your changes -->
git commit -m "Delete filename.ext"
<!-- -------------------------------------------- -->
<!-- Push to Github -->
<!-- Replace main with your specific branch name if it is different -->
git push origin main

# Branching in Github
# ----------------------------------------------------
<!-- Step 1: Sync Your Local Repository -->
<!-- Before creating a new branch, always update your local machine with the latest changes from GitHub -->
<!-- Switch to your main branch -->
git checkout main

<!-- Fetch and download the latest updates -->
git pull origin main
<!-- -------------------------------------------- -->
<!-- Step 2: Create and Switch to Your New Branch -->
<!-- Create and immediately switch to the new branch -->
git checkout -b your-branch-name
<!-- (Alternatively, you can create a branch directly on the web interface by clicking the main dropdown menu on your GitHub repository page and typing a new name) -->
<!-- -------------------------------------------- -->
<!-- Step 3: Work and Commit Changes -->
<!-- Track the modified files -->
git add .

<!-- Save a snapshot of your progress locally -->
git commit -m "Add secure password validation to login form"
<!-- -------------------------------------------- -->
<!-- Step 4: Publish Your Branch to GitHub -->
<!-- Push the branch up to GitHub -->
git push origin your-branch-name

<!-- -------------------------------------------- -->
# Step 5: Merge via Pull Request (PR) -->
<!-- Once your code is ready, merge it back into the main codebase using the GitHub Web Interface -->
<!-- 
1. Go to your repository on GitHub.com.
2. Click the Compare & pull request button that automatically appears at the top.
3. Add a description explaining your changes.
4. Click Create pull request.
5. Review the code changes (or have a teammate review them).
6. Click Merge pull request and then Confirm merge to combine it with the main branch -->

# Standard Terminal merge workflow 
1. Switch back to your main target branch 
git checkout main

2. Pull the latest online updates to prevent conflicts
git pull origin main

3. Merge your feature branch into main
git merge your-branch-name

4. Upload the newly merged main branch back to GitHub
git push origin main

<!-- -------------------------------------------- -->
<!-- Step 6: Clean Up -->
<!-- After merging, delete the temporary branch to keep your environment tidy -->
<!-- On GitHub: Click the Delete branch button directly inside the closed Pull Request page. -->
<!-- On Local Machine: Switch back to main, pull the newly merged code, and erase the local copy: -->
<!-- 
    1. git checkout main
    2. git pull origin main 
    3. git branch -d your-branch-name 
-->
