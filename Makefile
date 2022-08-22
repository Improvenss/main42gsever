git:
	git add .
	git commit -m "$m"
	git push

submodule_update:
	git submodule update --init ready-for-pusht/
	git submodule update --init projes/main/
# NOTE: git push origin HEAD:master
# NOTE: git clone --recurse-submodules <repository url>
# NOTE: git pull origin master
