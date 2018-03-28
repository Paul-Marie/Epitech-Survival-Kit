import sys
import math
import os
import random
from fractions import Fraction
from decimal import Decimal

def     aff_key(key, nb, key_av):
    i = 0
    j = 0
    k = 0
    while (i < nb):
        key.append([])
        while (j < nb and k < len(key_av)):
            key[i].append(ord(key_av[k]))
            j = j + 1
            k = k + 1
        i = i + 1
        j = 0
    while (len(key[i - 2]) < nb):
        key[i - 2].append(0)
    while (len(key[i - 1]) < nb):
        key[i - 1].append(0)
    return key

def     sym_key(key, nb):
    stock = key[0][1]
    key[0][1] = key[1][0]
    key[1][0] = stock
    stock = key[0][2]
    key[0][2] = key[2][0]
    key[2][0] = stock
    stock = key[1][2]
    key[1][2] = key[2][1]
    key[2][1] = stock
    return key

def     fois_key_inv(key, nb, i, j, det):
    result = 0;
    if (i == 0):
        i_1 = 1
        i_2 = 2
    elif (i == 1):
        i_1 = 0
        i_2 = 2
    elif (i == 2):
        i_1 = 0
        i_2 = 1
    if (j == 0):
        j_1 = 1
        j_2 = 2
    elif (j == 1):
        j_1 = 0
        j_2 = 2
    elif (j == 2):
        j_1 = 0
        j_2 = 1
    foo = (Fraction(1, det))
    result = foo * (key[i_1][j_1] * key[i_2][j_2] - key[i_2][j_1] * key[i_1][j_2])
    if (i == 0 and j == 1 or i == 1 and j == 0 or i == 2 and j == 1 or i == 1 and j == 2):
        fois = -1
    else:
        fois = 1
    if (result != 0):
        return ((result) * fois)
    else:
        return float(0)

def     key_inv_3x3(key, nb):
    det = key[0][0] * (key[1][1] * key[2][2] - key[2][1] * key[1][2]) - key[0][1] * (key[1][0] * key[2][2] - key[2][0] * key[1][2]) + key[0][2] * (key[1][0] * key[2][1] - key[2][0] * key[1][1])
    key_int = []
    i = 0
    j = 0
    key = sym_key(key, nb)
    while (i < nb):
        key_int.append([])
        while (j < nb):
            key_int[i].append(fois_key_inv(key, nb, i, j, det))
            j = j + 1
        i = i + 1
        j = 0
    return key_int

def     aff_ph(ph, nb, nbr, sent):
    i = 0
    j = 0
    k = 0
    while (i < nbr):
        if (len(ph) != nbr):
            ph.append([])
        while (j < nb and k < len(sent)):
            ph[i].append(ord(sent[k]))
            j = j + 1
            k = k + 1;
        i = i + 1
        j = 0;
    if (len(ph[i - 1]) != nb):
        while (len(ph[i - 1]) < nb):
            ph[i - 1].append(0)
    return ph

def     matrix_ph(ph, nb, nbr, tab):
    i = 0
    j = 0
    k = 0
    while (i < nbr):
        ph.append([])
        while (j < nb and k < len(tab)):
            ph[i].append(my_put_nbr(tab[k]))
            j = j + 1
            k = k + 1;
        i = i + 1
        j = 0;
    return ph

def     aff_cript_ph(ph, nb, nbr, sent):
    tab = []
    i = 0
    j = 0
    while (i < len(sent)):
        tab.append([])
        while (i < len(sent) and ord(sent[i]) != ord(' ')):
            tab[j].append(sent[i])
            i = i + 1
        i = i + 1
        j = j + 1
    pf = matrix_ph(ph, nb, nbr, tab)
    return ph

def     my_put_nbr(tab):
    decim = 1
    b = 0
    c = 0
    result = 0
    while (c != len(tab)):
        decim = decim * 10
        c = c + 1
    decim = decim / 10
    while (decim > 0):
        result = result + (ord(tab[b]) - 48) * decim
        decim = decim / 10
        b = b + 1
    return result

def     aff_res(res, nb, nbr, key, ph):
    stock = float(0)
    i = 0
    j = 0
    k = 0
    while (i < nbr):
        while (j < nb):
            while (k < nb):
                stock = float(stock) + float(key[k][j]) * float(ph[i][k])
                k = k + 1
            res.append(stock)
            stock = float(0)
            k = 0
            j = j + 1
        i = i + 1
        j = 0
    return res

def     cipher(sent, key_av, mod):
    #################################
    # Declaration variables
    key = []
    ph = []
    res = []
    if (float(math.sqrt(len(key_av))) % 1 == 0):
        nb = int(math.sqrt(len(key_av)))
    else:
        nb = int(math.sqrt(len(key_av))) + 1
    if (nb == 0):
        exit(84)
    if (mod == 0):
        if ((float(len(sent)) / nb) % 1 == 0):
            nbr = int(len(sent) / nb)
        else:
            nbr = int(len(sent) / nb) + 1
    else:
        i = 0
        j = 1
        while (i < len(sent)):
            if (sent[i] == ' '):
                j = j + 1
            i = i + 1
        nbr = int(j / nb)

    #################################
    # Affectation variables principales
    key = aff_key(key, nb, key_av)
    if (mod == 0):
        ph = aff_ph(ph, nb, nbr, sent)
    else:
        ph = aff_cript_ph(ph, nb, nbr, sent)
        key = key_inv_3x3(key, nb)
    res = aff_res(res, nb, nbr, key, ph)

    i = 0
    while (i < len(res)):
        if (mod == 0):
            res[i] = int(res[i])
        else:
            if (res[i] != 0):
                res[i] = chr(int(round(res[i])))
            else:
                len_res = len(res)
                while (i < len_res):
                    res.pop()
                    i = i + 1
        i = i + 1
    return res
