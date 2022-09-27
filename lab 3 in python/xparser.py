import xtokens as t
import xlexer as xl

from utils import Peekable

def parse(char_stream):
    tokens = Peekable(xl.lex(char_stream), 1)
    _list(tokens)
    _match(tokens, t.Eof)

def _list(tokens):
    _match(tokens, t.Lbrack)
    _elements(tokens)
    _match(tokens, t.Rbrack)

def _elements(tokens):
    _element(tokens)
    while tokens[0] == t.Comma():
        next(tokens)
        _element(tokens)

def _element(tokens):
    match tokens[0]:
        case t.Ident(s):
            next(tokens)
        case token:
            raise ValueError(f"Invalid token {token}")

def _match(tokens, token_type):
    if isinstance(tokens[0], token_type):
        next(tokens)
    else:
        raise ValueError(f"Failed to match {tokens[0]} to type {token_type}")