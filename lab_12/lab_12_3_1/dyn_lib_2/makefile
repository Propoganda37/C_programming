# Компилятор
CC := gcc

# Катологи
OUT_DIR := out
SRC_DIR := src
INC_DIR := inc
UNIT_DIR := unit_tests

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -Wno-unused-result -Wfloat-equal -Wfloat-conversion -Wextra -I$(INC_DIR)
DEBUG_FLAGS := -g3 -O0
RELEASE_FLAGS := -g0 -O2


END_FLAGS := -ldl
UNIT_FLAGS := -lcheck -lpthread -lrt


LIB_OBJS := $(OUT_DIR)/sort.o $(OUT_DIR)/filter.o $(OUT_DIR)/inout.o

# Все С файлы
SRCS := $(wildcard $(SRC_DIR)/*.c)
UNITS := $(wildcard $(UNIT_DIR)/*.c)

# Цель по умолчанию
all: release


debug : CFLAGS += $(DEBUG_FLAGS)
debug : app.exe



# Финальная сборка
release : CFLAGS += $(RELEASE_FLAGS)
release : app.exe

# Цель для сборки статической библиотеки
lib: CFLAGS += $(RELEASE_FLAGS)
lib: libprocess.so

# Модульные тесты
unit : unit_tests.exe
unit :
	./unit_tests.exe

# Функциональные тесты
func: release
func:
	./func_tests/scripts/func_tests.sh -v


sanitizers:
	./check_sanitizers.sh

valgrind:
	./func_tests/scripts/func_tests.sh -valgrind

coverage:
	./collect_coverage.sh



clean :
	$(RM) $(OUT_DIR)/*.o $(OUT_DIR)/*.d *.exe *.so *.a ./*.gcda ./*.gcno ./*.gcov ./func_tests/res.txt


app.exe : $(OUT_DIR)/main.o libprocess.so
	$(CC) $(OUT_DIR)/main.o -o $@ $(END_FLAGS)

unit_tests.exe: $(OUT_DIR)/check_sort.o $(OUT_DIR)/check_filter.o $(OUT_DIR)/check_main.o libprocess.so
	$(CC) $(OUT_DIR)/check_sort.o $(OUT_DIR)/check_filter.o $(OUT_DIR)/check_main.o -o $@ $(UNIT_FLAGS) $(END_FLAGS)

libprocess.so: $(LIB_OBJS)
	$(CC) -shared -o $@ $^



$(OUT_DIR)/main.o : $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@


$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OUT_DIR)/%.o : $(UNIT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.d : $(SRC_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	$(CC) -MM $< -I$(INC_DIR) > $@

$(OUT_DIR)/%.d : $(UNIT_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	$(CC) -MM $< -I$(INC_DIR) > $@

include $(SRCS:$(SRC_DIR)/%.c=$(OUT_DIR)/%.d)

include $(UNITS:$(UNIT_DIR)/%.c=$(OUT_DIR)/%.d)

.PHONY : clean debug release unit func sanitizers valgrind coverage lib