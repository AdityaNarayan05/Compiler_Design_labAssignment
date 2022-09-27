from dataclasses import dataclass

@dataclass
class Lbrack:
    pass

@dataclass
class Rbrack:
    pass

@dataclass
class Equal:
    pass

@dataclass
class Comma:
    pass

@dataclass
class Eof:
    pass

@dataclass
class Ident:
    s : str