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

# Общие объектные файлы
OBJS := $(OUT)/my_snprintf.o

# Объединяем С файлы
SRCS := $(wildcard $(SRC)/*.c)
UNITS := $(wildcard $(UNIT_DIR)/*.c)

# Цель по умолчанию
all: release

# debug сборка
debug : CFLAGS += -g3 -O0
debug : app.exe

# release сборка
release : CFLAGS += -g0 -O2
release : app.exe

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
	$(RM) $(OUT)/*.o $(OUT)/*.d $(OUT)/*.txt *.exe *.txt *.gcno *.gcda *.gcov

# Получение исполняемого файла
app.exe : $(OUT)/main.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(END_FLAGS)

# Получение исполняемого файла для модульного тестирования
unit_tests.exe: $(OUT)/check_my_snprintf.o $(OUT)/check_main.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@  $(END_FLAGS) $(UNIT_FLAGS)

# Получение объектных файлов
$(OUT)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)/%.o : $(UNIT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Получение файлов с зависимостями
$(OUT)/%.d : $(SRC)/%.c
	@mkdir -p $(OUT)
	$(CC) -MM $< -I$(INC) > $@

$(OUT)/%.d : $(UNIT_DIR)/%.c
	@mkdir -p $(OUT)
	$(CC) -MM $< -I$(INC) > $@

include $(SRCS:$(SRC)/%.c=$(OUT)/%.d)

include $(UNITS:$(UNIT_DIR)/%.c=$(OUT)/%.d)

.PHONY : clean debug release unit func sanitize coverage valgrind
