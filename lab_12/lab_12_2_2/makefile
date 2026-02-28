# Компилятор
CC := gcc

# Папки
OUT := out
SRC := src
INC := inc
UNIT_DIR := unit_tests

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -Wno-unused-result -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -I$(INC)
END_FLAGS := -lm
UNIT_FLAGS := -lcheck -lpthread -lrt


LIB_OBJS := $(OUT)/libprocess.o

# Объединяем С файлы
SRCS := $(wildcard $(SRC)/*.c)
UNITS := $(wildcard $(UNIT_DIR)/*.c)

go: release
go:
	python3 $(SRC_DIR)/interface.py

# Цель по умолчанию
all: release

# debug сборка
debug : CFLAGS += -g3 -O0
debug : app.exe

# release сборка
release : CFLAGS += -g0 -O2
release : app.exe

# Цель для сборки статической библиотеки
lib: CFLAGS += -g3 -O0
lib: libprocess.so

# Модульные тесты
unit : unit_tests.exe
unit :
	./unit_tests.exe

# Функциональные тесты
func: release
func:
	./func_tests/scripts/func_tests.sh
	
# Функциональные тесты с valgrind
valgrind: debug
valgrind:
	./func_tests/scripts/func_tests.sh -val
	
# Проверка санитайзерами
sanitize:
	./sanitize_check.sh
	
# Проверка покрытия
coverage:
	./collect_coverage.sh

# Очистка
clean :
	$(RM) $(OUT)/*.o $(OUT)/*.d $(OUT)/*.txt *.exe *.so *.a ./*.gcda ./*.gcno ./*.gcov

unit_tests.exe: $(OUT)/check_insert.o $(OUT)/check_prime.o $(OUT)/check_main.o libprocess.so
	$(CC) $^ -o $@ -L. -lprocess $(END_FLAGS) $(UNIT_FLAGS) -Wl,-rpath,.

libprocess.so: $(LIB_OBJS)
	$(CC) -o $@ -shared $^



$(OUT_DIR)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OUT_DIR)/%.o : $(UNIT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.d : $(SRC)/%.c
	@mkdir -p $(OUT_DIR)
	$(CC) -MM $< -I$(INC_DIR) > $@

$(OUT_DIR)/%.d : $(UNIT_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	$(CC) -MM $< -I$(INC_DIR) > $@

include $(SRCS:$(SRC)/%.c=$(OUT)/%.d)

include $(UNITS:$(UNIT_DIR)/%.c=$(OUT)/%.d)

.PHONY : clean debug release unit
