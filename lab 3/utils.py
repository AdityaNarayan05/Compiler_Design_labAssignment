class Peekable:
    def __init__(self, input_, k, sentinel=None):
        self.sentinel = sentinel
        self._k = k
        self._stream = iter(input_)
        self._peek = [next(self._stream, sentinel) for _ in range(k)]

    def __getitem__(self, n):
        if isinstance(n, int) and n >= self._k:
            raise IndexError(f"Invalid lookahead index {n} on Peekable with k={self._k}")
        return self._peek[n]

    def __iter__(self):
        return self

    def __next__(self):
        if self._peek[0] == self.sentinel:
            raise StopIteration
        res = self._peek[0]
        self._peek = self._peek[1:]
        self._peek.append(next(self._stream, self.sentinel))
        return res