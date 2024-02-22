DIRS = $(wildcard */)
DIR_NAMES = $(DIRS:/=)
ZIP_TARGETS = $(addsuffix /學號_姓名.zip, $(DIR_NAMES))

debug:
	@echo $(DIRS)
	@echo $(DIR_NAMES)
	@echo $(ZIP_TARGETS)

clean: 
	find . -type f -name "*.zip" -delete

$(ZIP_TARGETS):
	@echo $@
	cd $(dir $@) && zip -ur $(notdir $@) * -x '*.vs/*' '*x64/*' '*.zip'

zip_projects: $(ZIP_TARGETS)