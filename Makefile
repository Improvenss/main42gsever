git:
	git add .
	git commit -m "$m"
	git push

submodule_update:
	git submodule update --init --recursive --remote -j 8
	git submodule update --remote
#	git pull --recurse-submodules -j 8
# NOTE: git push origin HEAD:master
# NOTE: git clone --recurse-submodules <repository url>
# NOTE: git pull origin master
# NOTE: git clone --depth 1 -> sadece en son commit'i aliyor
# NOTE: git checkout acc9a87 -> hangi commit'e gitmek istiyorsan ona gidiyor
