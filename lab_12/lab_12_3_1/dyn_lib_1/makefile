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

LIB_OBJS := $(OUT)/sort.o $(OUT)/filter.o $(OUT)/inout.o

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

# Получение исполняемого файла
app.exe : $(OUT)/main.o libprocess.so
	$(CC) $^ -o $@ -L. -lprocess $(END_FLAGS) -Wl,-rpath,.

# Получение исполняемого файла для модульного тестирования 
unit_tests.exe: $(OUT)/check_sort.o $(OUT)/check_filter.o $(OUT)/check_main.o libprocess.so
	$(CC) $^ -o $@ -L. -lprocess $(END_FLAGS) $(UNIT_FLAGS) -Wl,-rpath,.

# Компиляция библиотеки
libprocess.so: $(LIB_OBJS)
	$(CC) -shared -o $@ $^

# Получение объектных файлов
$(OUT)/main.o : $(SRC)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

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

.PHONY : clean debug release unit func sanitizers valgrind coverage lib
