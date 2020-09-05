from Server.Instruments.stepper import Stepper
from Server.Instruments.harp import Harp


# List of available instruments
instruments_list = [
    Stepper(index=1),
    Stepper(index=2),
    Stepper(index=3),
    Harp(),
]