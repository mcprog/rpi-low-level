CC = gcc
CFLAGS = -Wall
LIBS = -lwiringPi
SRC_DIR = src
BUILD_DIR = build

# eg) make build/LightWater
$(BUILD_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)
#eg make thread/ColorfulLED
thread/%: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $(BUILD_DIR)/$* $(LIBS) -lpthread

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean