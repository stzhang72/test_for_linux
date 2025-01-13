savedcmd_/home/stzhang/A_my_code/aa/myfs/myfs.mod := printf '%s\n'   myfs.o | awk '!x[$$0]++ { print("/home/stzhang/A_my_code/aa/myfs/"$$0) }' > /home/stzhang/A_my_code/aa/myfs/myfs.mod
