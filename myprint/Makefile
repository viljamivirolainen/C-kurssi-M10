MAIN_DIR = src
TEST_DIR = test

.PHONY: main test

main:
	$(MAKE) -C $(MAIN_DIR)

all: main test

test:
	$(MAKE) -C $(TEST_DIR)

clean:
	$(MAKE) -C $(MAIN_DIR) clean
	$(MAKE) -C $(TEST_DIR) clean

run-main:
	$(MAKE) -C $(MAIN_DIR) run

run-test:
	$(MAKE) -C $(TEST_DIR) run
valgrind-test:
	$(MAKE) -C $(TEST_DIR) valgrind

run-test-json:
	$(MAKE) -C $(TEST_DIR) run-json
valgrind-test-json:
	$(MAKE) -C $(TEST_DIR) valgrind-json

get-points:
	$(MAKE) -C $(TEST_DIR) get-points

get-results:
	$(MAKE) -C $(TEST_DIR) get-results
