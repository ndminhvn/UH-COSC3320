import math

memory = []

def request_page(page, mem_size):
    # 1) The page is in already in memory, so we move it to the beginning of the list because it was most recently used (no page reads or writes)
    # 2) The page is not in memory, but there is room to add it. (1 page read)
    # 3) The page is not in memory, and a victim needs to be chosen. We remove the last page in the memory list, which needs to be written to external memory.
    #    Then we need to read the requested page from external memory (1 page read, 1 page write)
    # This functions returns the amount of page reads / writes needed to carryout the page request
    if (page in memory):
        memory.remove(page)
        memory.insert(0, page)
        return 0
    elif (len(memory) < mem_size):
        memory.insert(0, page)
        return 1
    else:
        memory.pop()
        memory.insert(0, page)
        return 2
    
def calculate_page_transfers(page_size, array_size, mem_size):
    threshold = array_size / 10
    count = 0
    for i in range(array_size):
        # This just tracks the progress of the program, giving updates every 1/10 of the way
        if (i > threshold):
            print("{}% done ".format(threshold * 100 /array_size))
            threshold += array_size / 10
            for j in range(array_size):
    
                # calculate the page # for A[i, j]
                page1 = math.floor((i * array_size + j) / page_size)

                # calculate the page # for B[i, j] ... the array_size * array_size + page_size is just to make sure we dont get any of the same page #'s as the A array has
                page2 = math.floor((array_size * array_size + page_size + i * array_size + j) / page_size)
                
                # calculate the page # for C[j, n-i + 1] ... the 2 * array_size * array_size + page_size is just to make sure we dont get any of the same page #'s as the A or B arrays have
                page3 = math.floor((2 * array_size * array_size + page_size + j * array_size + array_size - i + 1) / page_size)

                # calculate the page # for A[j, i]
                page4 = math.floor((j * array_size + i) / page_size)

                # A[I, J] = A[I, J] * B[I, J]
                # First we request A[I, J]
                # Then we request B[I, J]
                # Then we multiply
                # Then we request A[I, J] to store the result
                count += request_page(page1, mem_size)
                count += request_page(page2, mem_size)
                count += request_page(page1, mem_size)
                
                # B[I, J] = C[J, N-I+1] * A[J, I]
                # First we request C[J, N-I+1]
                # Then we request A[J, I]
                # Then we multiply
                # Then we request B[I, J] to store the result
                count += request_page(page3, mem_size)
                count += request_page(page4, mem_size)
                count += request_page(page2, mem_size)
    return count
 

if __name__ == "__main__":
    page_transfers = calculate_page_transfers(2000, 4000, 1000)
    print("Page transfers: {}".format(page_transfers))