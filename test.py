import os

for file in os.listdir('.'):
    if file.startswith('lc') and file.endswith('.cpp'):
        start = 0
        end = file.rfind('.')
        for i in range(len(file)):
            if not file[i].isalnum():
                start = i
                break
        for i in range(-5, -len(file) - 1, -1):
            if not file[i].isalnum():
                end = i + 1
                break
        new_name = file[0:start]
        if file[end] != ".":
            new_name += "_"
        new_name += file[end:]
        os.rename(file, new_name)