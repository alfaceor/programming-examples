import numpy as np
import pandas as pd
import panel as pn
pn.extension()

Np = 10
XX = range(Np)
YY = np.random.random(Np)
df = pd.DataFrame({'X': XX, 'Y': YY})

def select_row(row=0):
    return df.loc[row]

def main():
    app = pn.interact(select_row, row=(0, len(df)-1))
    return app.show()

if __name__ == '__main__' :
    main()
