
# Returns a progress function that gives a fixed status and a percent that depends
# on the sum of the numbers in the progress list (The last number is the total)
def from_numbers_fixed_status(status):
    def function(progress):
        percent, total = 0, progress[-1]
        for val in progress[:-1]: percent += val
        percent = round(percent * 1000 / total) / 10
        return {'percent': percent, 'status': status}
    return function

# Returns a progress function that gives a fixed status and a percent that depends
# on the number of True booleans in the progress list
def from_boolean_fixed_status(status):
    def function(progress):
        percent, total = 0, len(progress)
        for val in progress:
            if val: percent += 1
        percent = round(percent * 1000 / total) / 10
        return {'percent': percent, 'status': status}
    return function
