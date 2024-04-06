#!/bin/python
from random import randint
from os import system

METRICA="FLOPS_DP"
CPU=3
# Compila o código
system("make") 

system(f"echo \"performance\" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor")

file_data = open("./sistemas.dat", "r")
# Lê o arquivo e separa as matrizes em um array
matrices = file_data.read().split("\n\n")

system(f"echo \"{matrices[0]}\" > example.txt")
system(f"./perfSL < example.txt")
system(f"likwid-perfctr -C \"{CPU}\" -g \"{METRICA}\" -m ./perfSL < example.txt | grep 'DP' | grep -v AVX")
system("rm example.txt")

file_data.close()

system(f"echo \"powersave\" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor")