#!/usr/bin/env python3
import sys
import subprocess
import random

from typing import Tuple

DEFAULT_AMOUNT = 4


def create_array(args):
    if len(args) == 1 and type(args[0]) == int:
        amount_nbs = args[0]
        my_nbs = set()
        for i in range(amount_nbs):
            my_nbs.add(random.randint(0, 10000))
        my_nbs = list(my_nbs)
        random.shuffle(my_nbs)
        random.shuffle(my_nbs)
    else:
        my_nbs = args
    return [str(x) for x in my_nbs]


def tester(*args) -> tuple:
    arg = create_array(args)
    # print(" ".join(arg))
    p = subprocess.Popen(f'ARG="{" ".join(arg)}"; ./push_swap $ARG | ./checker $ARG', shell=True,
                         stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout = p.stdout.read().decode('ascii')
    result, amount_ops = stdout[1:3], int(''.join(c for c in stdout if c.isdigit()))
    return result, amount_ops


def assert_amount_ops(test_input, amount_ops):
    max_ops = dict({
        3: 3,
        5: 12,
        100: 700,
        500: 5500
    })
    for key in max_ops:
        assert test_input > key or amount_ops < max_ops[key]


def get_average(test_input, amount_tests=10) -> Tuple[int, int]:
    print(f'Running tests for test input {test_input}!')
    total_ops = 0
    failure = 0
    for nb in range(amount_tests):
        result, amount_ops = tester(test_input)
        if result != 'OK':
            failure = 1
            print(f'KO on input "{test_input}"') and quit()
        try:
            assert_amount_ops(test_input, amount_ops)
        except AssertionError:
            failure = 1
            print(f'{amount_ops} instructions is too many!!!!')
        total_ops += amount_ops
    return int(total_ops / amount_tests), failure


# noinspection PyTypeChecker
def moulinette(argv):
    final_exit_status = 0
    for i in range(1, len(argv)):
        average_ops, status_code = get_average(int(argv[i]), 100)
        if status_code != 0:
            final_exit_status = status_code
        print(f'Average amount of operations for test {argv[i]} is {average_ops}')
    exit(final_exit_status)


if __name__ == "__main__":
    moulinette(sys.argv)
