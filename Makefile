CC = gcc
CFLAGS = -Wall
LIBS = -lwiringPi
SRC_DIR = src
BUILD_DIR = build

# eg) make build/LightWater
$(BUILD_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)
clean:
	rm -rf $(BUILD_DIR)

.PHONY clean