class CP1D:
    def __init__(self):
        self.q = 0
        self.v = 0
        self.a = 0

    def __str__(self):
        str_return = "q = " + str(self.q) + "\n"
        str_return = str_return + "v = " + str(self.v) + "\n"
        str_return = str_return + "a = " + str(self.a) + "\n"
        return str_return

    def update_q(self):
        self.q = self.q + 10
