import itertools
from typing import List, Tuple, Optional
import unittest

class ExpressionFinder:
    def __init__(self, filename: str):
        self.digits = self.read_digits(filename)

    def read_digits(self, filename: str) -> List[str]:
        with open(filename, 'r') as file:
            line = file.read().replace(',', ' ').replace('\n', ' ')
            return [d for d in line.split() if d.isdigit()]

    def find_expression(self, k: float) -> Optional[str]:
        n = len(self.digits)
        if n < 2:
            return None
        ops = ['+', '-', '*', '/', '']
        for op_tuple in itertools.product(ops, repeat=n-1):
            expr = self.digits[0]
            has_mul = has_div = False
            for i, op in enumerate(op_tuple):
                if op == '*': has_mul = True
                if op == '/': has_div = True
                expr += op + self.digits[i+1]
            if '*' in ops or '/' in ops:
                if not (has_mul or has_div):
                    continue
            try:
                val = self.eval_expr(expr)
                if val is not None and abs(val - k) < 1e-6:
                    return expr
            except:
                continue
        return None

    def eval_expr(self, expr: str) -> Optional[float]:
        num = ''
        tokens = []
        for ch in expr:
            if ch in '+-*/':
                tokens.append(num)
                tokens.append(ch)
                num = ''
            else:
                num += ch
        tokens.append(num)
        res = float(tokens[0])
        for i in range(1, len(tokens), 2):
            op = tokens[i]
            val = float(tokens[i+1])
            if op == '+':
                res += val
            elif op == '-':
                res -= val
            elif op == '*':
                res *= val
            elif op == '/':
                if val == 0:
                    return None
                res /= val
        return res

class ExpressionFinderTests(unittest.TestCase):
    def setUp(self):
        with open('test_digits1.txt', 'w') as f:
            f.write('1,2,3,4,2,2,1')
        with open('test_digits2.txt', 'w') as f:
            f.write('1 2 3')
        with open('test_digits3.txt', 'w') as f:
            f.write('9,9,9,9')
        with open('test_digits4.txt', 'w') as f:
            f.write('5')

    def test_example(self):
        finder = ExpressionFinder('test_digits1.txt')
        expr = finder.find_expression(45)
        self.assertIsNotNone(expr)
        val = finder.eval_expr(expr)
        self.assertAlmostEqual(val, 45, delta=1e-6)

    def test_no_solution(self):
        finder = ExpressionFinder('test_digits2.txt')
        expr = finder.find_expression(12345)
        self.assertIsNone(expr)

    def test_single_digit(self):
        finder = ExpressionFinder('test_digits4.txt')
        expr = finder.find_expression(5)
        self.assertIsNone(expr)

    def test_all_nines(self):
        finder = ExpressionFinder('test_digits3.txt')
        expr = finder.find_expression(9999)
        self.assertTrue(expr is None or abs(finder.eval_expr(expr) - 9999) < 1e-6)

if __name__ == "__main__":
    unittest.main()
