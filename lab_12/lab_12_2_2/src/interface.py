import ctypes
import tkinter as tk
from tkinter import ttk

lib = ctypes.CDLL('./libprocess.so')

_fill_primes = lib.fill_primes
_fill_primes.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_fill_primes.restype = ctypes.c_int

_copy_and_insert = lib.copy_and_insert
_copy_and_insert.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t, \
                ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_size_t), ctypes.c_int)
_copy_and_insert.restype = ctypes.c_int

# Функция для заполнения массива числами Фибоначчи
def fill_primes(n):
    if n > 0:
        size = n
    else:
        size = 0
    arr = (ctypes.c_int * size)()
    rc = _fill_primes(arr, n)

    return rc, list(arr)


# Функция для поиска первого вхождения каждого элемента массива
def copy_and_insert(nums, flag, num):
    size1 = len(nums)
    array1 = (ctypes.c_int * size1)(*nums)
    if (flag):
        size2 = ctypes.c_size_t(0)

        rc = _copy_and_insert(array1, size1, None, size2, num)
        if rc == 0:
            array2 = (ctypes.c_int * size2.value)()
            rc = _copy_and_insert(array1, size1, array2, size2, num)
            return rc, list(array2)
        else:
            return rc, list()
    else:
        size2 = ctypes.c_size_t(size1 * 2)
        array2 = (ctypes.c_int * size2.value)()
        rc = _copy_and_insert(array1, size1, array2, size2, num)
        return rc, list(array2[:size2.value])


def on_combo2_change(event):
    choice = combo1.get()
    if choice == "Простые числа":
        instruction_label.config(text="Введите положительное кол-во простых чисел")
        combo1_label.grid_remove()
        combo2.grid_remove()
        extra_element_label.grid_remove()
        extra_element_entry.grid_remove()
    elif choice == "Добавить после четных элемент":
        instruction_label.config(text="Введите массив целых чисел через пробел")
        combo1_label.grid()
        combo2.grid()
        extra_element_label.grid()
        extra_element_entry.grid()


def on_button_click():
    choice2 = combo2.get()
    choice1 = combo1.get()
    input_text = entry.get()

    output_text_widget.delete("1.0", tk.END)

    if choice1 == "Простые числа":
        try:
            n = int(input_text)
        except ValueError:
            output_text_widget.insert(tk.END, "Некорректный ввод")
            return
        
        rc, arr = fill_primes(n)

        if rc == 0:
            output_text = ', '.join(map(str, arr))
        elif rc == 1:
            output_text="Введено некорректное кол-во простых чисел"
    elif choice1 == "Добавить после четных элемент":
        if choice2 == "Выделить память с запасом":
            flag = False
        elif choice2 == "Узнать требуемый объем памяти и выделить":
            flag = True
        else:
            output_text_widget.insert(tk.END, "Выберите способ выделения памяти")
            return
        try:
            nums = list(map(int, input_text.split()))
            extra_element = int(extra_element_entry.get())
        except ValueError:
            output_text_widget.insert(tk.END, "Некорректный ввод")
            return

        rc, arr = copy_and_insert(nums, flag, extra_element)
        if rc == 0:
            output_text = ', '.join(map(str, arr))
        elif rc == 2:
            output_text="Входной массив пуст"
    else:
        output_text="Выберите действие"

    output_text_widget.insert(tk.END, output_text)


# Создаем главное окно
root = tk.Tk()
root.title("Приложение")
root.configure(bg='#25204a')

# Первый выпадающий список
combo1_label = tk.Label(root, text="Выделение памяти", bg='#25204a', fg='white')
combo1_label.grid(row=2, column=0, pady=5, padx=10, sticky='ew')
combo2 = ttk.Combobox(root, values=["Выделить память с запасом", "Узнать требуемый объем памяти и выделить"], width=30, state="readonly")
combo2.grid(row=3, column=0, pady=5, padx=10, sticky='ew')

# Второй выпадающий список
combo2_label = tk.Label(root, text="Действие", bg='#25204a', fg='white')
combo2_label.grid(row=0, column=0, pady=5, padx=10, sticky='ew')
combo1 = ttk.Combobox(root, values=["Простые числа", "Добавить после четных элемент"], width=30, state="readonly")
combo1.grid(row=1, column=0, pady=5, padx=10, sticky='ew')
combo1.bind("<<ComboboxSelected>>", on_combo2_change)

# Инструкция
instruction_label = tk.Label(root, text="", bg='#25204a', fg='white', anchor='w')
instruction_label.grid(row=4, column=0, pady=5, padx=10, sticky='ew')

# Поле ввода и кнопка
frame = tk.Frame(root, bg='#25204a')
frame.grid(row=5, column=0, pady=5, padx=10, sticky='ew')

entry_label = tk.Label(frame, text="Ввод", bg='#25204a', fg='white')
entry_label.pack(side=tk.LEFT, padx=5)

entry = tk.Entry(frame, width=30)
entry.pack(side=tk.LEFT, padx=5, expand=True, fill='x')

button = tk.Button(frame, text="ОК", command=on_button_click)
button.pack(side=tk.LEFT, padx=5)

# Поле для ввода дополнительного элемента
extra_element_label = tk.Label(root, text="Элемент для вставки", bg='#25204a', fg='white')
extra_element_label.grid(row=6, column=0, pady=5, padx=10, sticky='ew')

extra_element_entry = tk.Entry(root, width=30)
extra_element_entry.grid(row=7, column=0, pady=5, padx=10, sticky='ew')

# Поле вывода с прокруткой
output_frame = tk.Frame(root, bg='#25204a')
output_frame.grid(row=8, column=0, pady=5, padx=10, sticky='nsew')

output_text_widget = tk.Text(output_frame, wrap='word', height=10, bg='#1f1b39', fg='white')
output_text_widget.pack(side=tk.LEFT, fill='both', expand=True)

scrollbar = tk.Scrollbar(output_frame, command=output_text_widget.yview)
scrollbar.pack(side=tk.RIGHT, fill='y')

output_text_widget.config(yscrollcommand=scrollbar.set)

# Настройка сетки
root.grid_rowconfigure(8, weight=1)
root.grid_columnconfigure(0, weight=1)

combo1_label.grid_remove()
combo2.grid_remove()

# Запуск главного цикла
root.mainloop()
