MODULES = 
BOARD ?= edu-ciaa-nxp
MUJU ?= ~/Documents/EITI_SistemasEmbebidos/Proyectos/muju
OUT_DIR ?= ./build

include $(MUJU)/modules/base/makefile

doc:
	@mkdir -p $(OUT_DIR)
	@doxygen