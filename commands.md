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
