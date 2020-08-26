#!/usr/bin/python3
''' This program overwrites a string in the heap of a given process '''
from sys import argv
import sys


def main():
        ''' This is the main function for overwriting a string in the heap of
        a given process '''

        if len(argv) != 4:
                usage_and_exit()
        try:
                pid = int(argv[1])
        except ValueError as e:
                usage_and_exit()
        if pid <= 0 or len(argv[2]) == 0 or len(argv[3]) == 0:
                usage_and_exit()
        searching = argv[2]
        replacing = argv[3]
        replacing = replacing.ljust(len(searching), '\00')
        maps_path = "/proc/{}/maps".format(pid)
        mem_path = "/proc/{}/mem".format(pid)
        dictio = getting_maps_info(maps_path)
        mem_overwriting(mem_path, dictio, searching, replacing)
        exit()


def mem_overwriting(mempath, dictio, searching, replacing):
        '''
        Function for overwriting the string in the heap of the process
        pointed out by mempath
        '''
        try:
                memop = open(mempath, 'rb+')
        except IOError as e:
                error_exit(e)
        with memop as memory:
                memory.seek(dictio['add_start'])
                heap = memory.read(dictio['add_end'] - dictio['add_start'])
                try:
                        position = heap.index(bytes(searching, "ASCII"))
                except Exception as e:
                        memop.close()
                        print("The string {} was not found in this section"
                              .format(searching))
                        exit(1)
                memory.seek(dictio['add_start'] + position)
                memory.write(bytes(replacing, "ASCII"))


def getting_maps_info(mapspath):
        '''
        Function to get relevant info from the /proc/<PID>/maps file
        '''
        proc_info = {}
        try:
                op = open(mapspath, 'r')
        except IOError as e:
                print("This file is nonexistent")
                error_exit(e)
        for lines in op:
                each = lines.split(" ")
                if "[heap]" in each[-1]:
                        proc_info['address'] = each[0]
                        proc_info['perms'] = each[1]
                        break
        addresses = proc_info['address'].split("-")
        if "rw" not in proc_info['perms']:
                print("There are not permissions for reading/writting")
                op.close()
                exit()
        if len(addresses) == 2:
                proc_info['add_start'] = int(addresses[0], 16)
                proc_info['add_end'] = int(addresses[1], 16)
                op.close()
                return(proc_info)
        else:
                print("There are not two directions!")
                op.close()
                exit()


def usage_and_exit():
        '''
        Generic function for printing instructions and exit
        '''
        u = "Usage: ./read_write_heap.py [PID = int][search_string]"
        ut = "[replace_string]\nPID must be an integer"
        print(u + ut)
        exit(1)


def error_exit(e):
        '''
        Function for printing errors and exit
        '''
        print("{}: {}".format(e.errno, e.strerror))
        exit()
if __name__ == "__main__":
        main()
