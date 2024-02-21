DIRS = $(wildcard */)
DIR_NAMES = $(DIRS:/=)
ZIP_TARGETS = $(addsuffix /<學號>_<姓名>.zip, $(DIR_NAMES))

debug:
	@echo $(DIRS)
	@echo $(DIR_NAMES)
	@echo $(ZIP_TARGETS)

clean: 
	find . -type f -name "*.zip" -delete

$(ZIP_TARGETS):
	@echo $@
	zip -ur $@ $(dir $@) -x '*/.vs/*' '*/x64/*' '*/x86/*'

zip_projects: $(ZIP_TARGETS)