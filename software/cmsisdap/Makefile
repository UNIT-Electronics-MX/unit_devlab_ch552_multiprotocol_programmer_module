# ===================================================================================
# Project:  CH55x Makefile Template 
# Author:   Stefan Wagner
# Modification: 2022-10-01
# Year:     2022
# URL:      https://github.com/wagiminator
# ==================================================================================
# Update:   2025-04-15
# Author:   Cesar Bautista
# ===================================================================================         
# Type "make help" in the command line.
# ===================================================================================

# Archivos y carpetas
MAINFILE   = main.c
TARGET     = main
INCLUDE    = src
TOOLS      = tools
BUILD_DIR  = build

# Configuración del microcontrolador
FREQ_SYS   = 16000000
XRAM_LOC   = 0x0200
XRAM_SIZE  = 0x0200
CODE_SIZE  = 0x3800

# Toolchain
CC         = sdcc
OBJCOPY    = objcopy
PACK_HEX   = packihx
ISPTOOL   ?= python3 $(TOOLS)/chprog.py $(BUILD_DIR)/$(TARGET).bin

# Flags de compilación
CFLAGS  = -mmcs51 --model-small --no-xinit-opt -DF_CPU=$(FREQ_SYS) -I$(INCLUDE) -I.
CFLAGS += --xram-size $(XRAM_SIZE) --xram-loc $(XRAM_LOC) --code-size $(CODE_SIZE)

# Archivos fuente y objetos
CFILES  = $(MAINFILE) $(wildcard $(INCLUDE)/*.c)
RFILES  = $(patsubst %.c,$(BUILD_DIR)/%.rel,$(notdir $(CFILES)))

# Archivos a limpiar
CLEAN_FILES = *.ihx *.lk *.map *.mem *.lst *.rel *.rst *.sym *.asm *.adb

# Mostrar ayuda
help:
	@echo "Comandos disponibles:"
	@echo "make all     -> Compila y construye todo"
	@echo "make hex     -> Genera $(TARGET).hex"
	@echo "make bin     -> Genera $(TARGET).bin"
	@echo "make flash   -> Flashea el firmware a CH55x"
	@echo "make clean   -> Limpia archivos generados"

# Asegurar que existe el directorio de salida
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Compilación de main.c
$(BUILD_DIR)/main.rel: main.c | $(BUILD_DIR)
	@echo "Compilando $< ..."
	@$(CC) -c $(CFLAGS) -o $@ $<

# Compilación de src/*.c
$(BUILD_DIR)/%.rel: $(INCLUDE)/%.c | $(BUILD_DIR)
	@echo "Compilando $< ..."
	@$(CC) -c $(CFLAGS) -o $@ $<

# Enlazado
$(BUILD_DIR)/$(TARGET).ihx: $(RFILES)
	@echo "Enlazando IHX..."
	@$(CC) $(RFILES) $(CFLAGS) -o $@

# Generar HEX
$(BUILD_DIR)/$(TARGET).hex: $(BUILD_DIR)/$(TARGET).ihx
	@echo "Generando HEX..."
	@$(PACK_HEX) $< > $@

# Generar BIN
$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).ihx
	@echo "Generando BIN..."
	@$(OBJCOPY) -I ihex -O binary $< $@

# Flash al CH55x
flash: $(BUILD_DIR)/$(TARGET).bin size removetemp
	@echo "Flasheando a CH55x..."
	@$(ISPTOOL)

# Objetivos estándar
all: $(BUILD_DIR)/$(TARGET).bin $(BUILD_DIR)/$(TARGET).hex size

hex: $(BUILD_DIR)/$(TARGET).hex size removetemp

bin: $(BUILD_DIR)/$(TARGET).bin size removetemp

bin-hex: $(BUILD_DIR)/$(TARGET).bin $(BUILD_DIR)/$(TARGET).hex size removetemp

install: flash

# Mostrar uso de memoria
size:
	@echo "------------------"
	@echo "FLASH: $(shell awk '$$1 == "ROM/EPROM/FLASH" {print $$4}' $(BUILD_DIR)/$(TARGET).mem) bytes"
	@echo "IRAM:  $(shell awk '$$1 == "Stack" {print 248-$$10}' $(BUILD_DIR)/$(TARGET).mem) bytes"
	@echo "XRAM:  $(shell awk '$$1 == "EXTERNAL" {print $(XRAM_LOC)+$$5}' $(BUILD_DIR)/$(TARGET).mem) bytes"
	@echo "------------------"

# Limpieza
removetemp:
	@echo "Eliminando temporales..."
	@rm -f $(addprefix $(BUILD_DIR)/,$(CLEAN_FILES))

clean:
	@echo "Limpiando todo..."
	@rm -rf $(BUILD_DIR)
