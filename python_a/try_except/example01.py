#!/usr/bin/env python3

def divide(a:float, b:float):
    try:
        # Intentionally raise an error.
        x = a / b
    except Exception as e:
        # Except clause:
        print("- Error occurred")
        raise e
    else:
        print("-- Hi, this is the else block!")
        return x
    finally:
        # Finally clause:
        print("--- Finally is always executed!")


print('='*10)
aa = divide(10, 3)
print(aa)

print('='*10)
aa = divide(10, 5)
print(aa)

print('='*10)
aa = divide(10, 0)
print(aa)
