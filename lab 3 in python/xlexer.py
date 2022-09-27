import string

from utils import Peekable
import xtokens as t

def lex(char_iterable):
    stream = Peekable(char_iterable, 1)
    return _lex(stream)

def _lex(stream):
    while True:
        match stream[0]:
            case stream.sentinel:
                yield t.Eof()
                break
            case '[':
                next(stream)
                yield t.Lbrack()
            case ']':
                next(stream)
                yield t.Rbrack()
            case '=':
                next(stream)
                yield t.Equal()
            case ',':
                next(stream)
                yield t.Comma()
            case c if _is_letter(c):
                yield _lex_ident(stream)
            case c if c in string.whitespace:
                next(stream)
            case c:
                raise ValueError(f"Invalid character {c}")

def _lex_ident(stream):
    cs = []
    while _is_letter(stream[0]):
        cs.append(next(stream))
    return t.Ident(''.join(cs))

def _is_letter(c):
    return c in string.ascii_letters