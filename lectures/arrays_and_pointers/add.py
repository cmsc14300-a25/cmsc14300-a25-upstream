def add_val_to_end(lst, val):
    """ docstring omitted """    
    lst.append(val)

def empty_lst(lst):
    """ docstring omitted """
    lst = []

if __name__ == "__main__":
    lst1 = []
    for v in [10, 20, 30]:
        add_val_to_end(lst1, v)
    print(f"lst after loop: {lst1}")

    empty_lst(lst1)
    print(f"lst after empty: {lst1}");
        
