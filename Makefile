CXX ?= clang++
CXXFLAGS ?= -std=c++23 -Wall -Wextra -Wpedantic -O0 -g
INCLUDES := -Iinclude
CPPFLAGS ?=
LDFLAGS ?=
LDLIBS ?= -lfmt
BUILD_DIR := build
DEPFLAGS := -MMD -MP

FMT_PREFIX := $(shell brew --prefix fmt 2>/dev/null)
ifneq ($(FMT_PREFIX),)
CPPFLAGS += -I$(FMT_PREFIX)/include
LDFLAGS += -L$(FMT_PREFIX)/lib -Wl,-rpath,$(FMT_PREFIX)/lib
endif

TEST_SOURCES := $(shell find problems -name test.cpp)
TEST_BINS := $(patsubst problems/%/test.cpp,$(BUILD_DIR)/%/test,$(TEST_SOURCES))
TEST_DEPS := $(TEST_BINS:%=%.d)

.PHONY: list test test-all clean

list:
	@echo "Available problems:"
	@for f in $(TEST_SOURCES); do \
		echo " - $${f#problems/}" | sed 's#/test.cpp$$##'; \
	done

test:
ifndef PROBLEM
	$(error Usage: make test PROBLEM=arrays_and_hashing/two_sum)
endif
	@mkdir -p $(BUILD_DIR)/$(PROBLEM)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) problems/$(PROBLEM)/test.cpp -o $(BUILD_DIR)/$(PROBLEM)/test $(LDFLAGS) $(LDLIBS)
	@$(BUILD_DIR)/$(PROBLEM)/test

test-all: $(TEST_BINS)
	@set -e; \
	for t in $(TEST_BINS); do \
		echo "==> $$t"; \
		$$t; \
	done

$(BUILD_DIR)/%/test: problems/%/test.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) $< -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -rf $(BUILD_DIR)

-include $(TEST_DEPS)
