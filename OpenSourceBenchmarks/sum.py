# The results are recorded in this script.
def compare_to_ideal(name, tool, result, ideal):
    print('Perfect slice length for ', name, ':', len(ideal))
    print('Slice produced by', tool, 'for', name, 'is:', len(result))
    idealAsSet = set(ideal)
    resultsAsSet = set(result)
    redundant_statements = list(resultsAsSet - idealAsSet)
    missing_statements = list(idealAsSet - resultsAsSet)
    print('Redundant statements:', len(redundant_statements))
    print('Missing statements:', len(missing_statements))


def linenoise():
    PROJECT = 'linenoise'

    ideal = [658,652,650, 647, 646, 643, 639, 638, 636, 632, 632, 629, 628, 626, 619, 618, 616, 608, 507, 506, 505, 503, 499, 498]
    unravel = [658,652,650, 647, 646, 643, 639, 638, 636, 632, 632, 629, 628, 626, 619, 618, 616, 608, 507, 505, 503, 499, 498]
    llvm_slicer = [658,655,653,652,650, 647, 646, 643, 639, 638, 636, 632, 632, 629, 628, 626, 622, 620, 619, 618, 617, 616, 608, 507, 505, 503, 499, 498]
    frama_c = [658,652,650, 647, 646, 643, 639, 638, 636, 632, 632, 629, 628, 626, 619, 618, 616, 608, 507, 505, 503, 499, 498]
    compare_to_ideal(PROJECT, 'Unravel', unravel, ideal)
    compare_to_ideal(PROJECT, 'LLVM-Slicer', llvm_slicer, ideal)
    compare_to_ideal(PROJECT, 'Frama-C', frama_c, ideal)


def stb():
    PROJECT = 'stb'
    ideal =  [97, 98, 103, 119, 120, 252, 253, 254, 255, 256, 257, 258, 259, 260, 262, 263, 264, 271, 272, 273, 275, 276, 280, 285, 294]
    unravel = [294,285,273,272,271,254,253,252,120,119,98,97]
    llvm_slicer = [294, 292, 291, 290, 289, 288, 287, 286, 285, 283, 282, 281, 280, 278, 277, 276, 275, 273, 272, 271, 267, 266, 265, 264, 263, 262, 260, 259, 258, 257, 256, 255, 254, 253, 252, 120, 119, 103, 98, 97]
    frama_c = [97, 98, 103, 119, 120, 252, 253, 254, 255, 256, 257, 258, 259, 260, 262, 263, 264, 271, 272, 273, 275, 276, 280, 285, 294]
    compare_to_ideal(PROJECT, 'Unravel', unravel, ideal)
    compare_to_ideal(PROJECT, 'LLVM-Slicer', llvm_slicer, ideal)
    compare_to_ideal(PROJECT, 'Frama-C', frama_c, ideal)

def tiny_json():
    PROJECT = 'tiny-json'

    ideal = [452, 458, 459, 460, 462, 463, 464, 466, 467, 473, 474]
    unravel = [587, 582, 581, 571, 569, 568, 567, 560, 548, 547, 546, 538, 537,536, 535, 534, 505, 504, 503, 501, 499, 498, 494, 492, 491, 487, 486, 480, 478, 476, 474, 473, 471, 468, 466, 463, 462, 460, 459, 458, 452, 424, 423, 419, 416, 415, 406, 405, 402, 401, 400, 397, 396, 395, 393, 391, 390, 389, 388, 387, 377, 376, 375, 374, 366, 365, 364, 363, 355, 345, 335, 325, 323,322,321,309,308,307,306,297,295,294,284,283,281,280,279,269, 263,262, 260,258, 256, 255, 253,252, 250,247, 244, 233,232,231,230,221,220,219,218]
    llvm_slicer = [587,  582, 581, 571, 569, 568, 567, 560, 550, 548, 547, 546, 538, 537, 536, 535, 507, 505, 504, 503, 502, 501, 500, 499, 498, 497, 496, 495, 493, 492, 491, 490, 489, 488, 486, 485, 484, 483, 481, 480, 479, 478, 477, 476, 474, 473, 471, 470, 469, 468, 467, 466, 464, 463, 462, 461, 460, 459, 458, 456, 455, 453, 452, 439, 437, 436, 434, 433, 432, 431, 424, 423, 420, 419, 418, 417, 416, 415, 414, 412, 411, 410, 409, 408, 407, 406, 405, 403, 402, 401, 400, 398, 397, 396, 395, 394, 393, 391, 390, 389, 388, 387, 377, 376, 375, 374, 366, 365, 364, 363, 355,  345,  335, 325, 324, 323, 322, 321,  309, 308, 307, 306,  297, 296, 295, 294, 293,  284, 283, 282, 281, 280, 279, 278, 269,  267,  264, 263, 262, 261,  258, 257, 256, 255, 254, 253, 252, 250, 249, 248, 247, 245, 244, 233, 232, 231, 230, 229]
    frama_c = [] # function ptr error
    compare_to_ideal(PROJECT, 'Unravel', unravel, ideal)
    compare_to_ideal(PROJECT, 'LLVM-Slicer', llvm_slicer, ideal)
    pass

def main():
    linenoise()
    print('--')
    tiny_json()
    print('--')
    stb()

if __name__ == '__main__':
    main()