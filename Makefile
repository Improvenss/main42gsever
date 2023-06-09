git:
	git add .
	git commit -m "$m"
	git push

submodule_update:
	git submodule update --init --recursive --remote --depth 1 -j 8
	git submodule update --remote
#	git pull --recurse-submodules -j 8
# NOTE: git push origin HEAD:master
# NOTE: git clone --recurse-submodules <repository url>
# NOTE: git pull origin master
# NOTE: git clone --depth 1 -> sadece en son commit'i aliyor
# NOTE: git checkout acc9a87 -> hangi commit'e gitmek istiyorsan ona gidiyor
#
# GITHUB'S CREATE NEW REPOSITORY AREA
# echo "# asdf" >> README.md
# git init
# git add README.md
# git commit -m "first commit"
# git branch -M main
# git remote add origin git@github.com:Improvenss/asdf.git
# git push -u origin main

# How can i learn my ip addres?
#yuandre@Gorkems-MacBook-Pro ~ % curl ifconfig.me
#<yourPublicIpAddress>
#yuandre@Gorkems-MacBook-Pro ~ % ipconfig getifaddr en0
#<yourPrivateIpAddress>
#yuandre@Gorkems-MacBook-Pro ~ % ifconfig -l | xargs -n1 ipconfig getifaddr
#<yourPrivateIpAddress>
#debian@debian:~$ hostname -I | awk '{print $1}'
#<yourPrivateIpAddress>


# How can i send file transfer with ssh?
#scp <source> <destination>
#To copy a file from B to A while logged into B:
#scp /path/to/file username@a:/path/to/destination
#To copy a file from B to A while logged into A:
#scp username@b:/path/to/file /path/to/destination
#scp ~/Desktop/app.zip gorkem@192.168.64.15:/home/gorkem/Desktop/inception

#How can i remove fully any package in Debian?
#sudo apt purge <package>
#sudo apt purge nginx
