#include <avr/pgmspace.h>

s#include <avr/pgmspace.h>

static const uint8_t font_DejaVuSerif[] PROGMEM = {
    0xfe,0xfe,0x1e,0x1e,0x1e,0x3e,0x1e,0x7e,0xbe,0x1e,0xfe,0xfe,0xfe, // 33
    0xfe,0xfe,0x86,0x86,0xa6,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe, // 34
    0xfe,0xfe,0xf6,0xc6,0x82,0x86,0x86,0x86,0xce,0xae,0xfe,0xfe,0xfe, // 35
    0xfe,0xfe,0xfe,0xc6,0x86,0x8e,0x86,0xc6,0xa2,0x86,0xee,0xfe,0xfe, // 36
    0xfe,0xfe,0x36,0x6,0xe,0x6,0x82,0xc2,0x82,0xb2,0xfe,0xfe,0xfe, // 37
    0xfe,0xfe,0xce,0x9e,0x9e,0x9a,0x6,0x26,0x22,0xa6,0xfe,0xfe,0xfe, // 38
    0xfe,0xfe,0x8e,0xce,0xce,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe, // 39
    0xfe,0xfe,0xee,0xce,0x9e,0x9e,0x9e,0x9e,0x9e,0x8e,0xee,0xfe,0xfe, // 40
    0xfe,0xfe,0xde,0xee,0xce,0xee,0xee,0xce,0xee,0xce,0xfe,0xfe,0xfe, // 41
    0xfe,0xfe,0xde,0x8e,0x86,0x1e,0xde,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe, // 42
    0xfe,0xfe,0xfe,0xde,0xce,0xde,0x6,0xe,0xde,0xde,0xfe,0xfe,0xfe, // 43
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xde,0x9e,0x9e,0xfe,0xfe, // 44
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xe,0xe,0xfe,0xfe,0xfe,0xfe,0xfe, // 45
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xde,0x8e,0xfe,0xfe,0xfe, // 46
    0xfe,0xfe,0xce,0xce,0xce,0x9e,0xbe,0x1e,0x3e,0x3e,0x7e,0xfe,0xfe, // 47
    0xfe,0xfe,0xc6,0xb6,0xb2,0x3a,0x32,0xb2,0xb2,0x8e,0xfe,0xfe,0xfe, // 48
    0xfe,0xfe,0xbe,0x1e,0xde,0x9e,0x9e,0xde,0x9e,0xe,0xfe,0xfe,0xfe, // 49
    0xfe,0xfe,0xa6,0xb6,0xf6,0xf6,0xee,0xee,0x86,0x86,0xfe,0xfe,0xfe, // 50
    0xfe,0xfe,0x86,0xb6,0xf6,0xe2,0xc6,0xf2,0x92,0x86,0xfe,0xfe,0xfe, // 51
    0xfe,0xfe,0xee,0xce,0x8e,0xa6,0x6,0x46,0xee,0xc6,0xfe,0xfe,0xfe, // 52
    0xfe,0xfe,0x86,0x9e,0x86,0xb6,0xf2,0xf2,0x96,0x86,0xfe,0xfe,0xfe, // 53
    0xfe,0xfe,0xe6,0xbe,0x1e,0xb2,0x3a,0x32,0xba,0xc6,0xfe,0xfe,0xfe, // 54
    0xfe,0xfe,0x82,0x96,0xf6,0xe6,0xee,0xee,0xde,0xde,0xfe,0xfe,0xfe, // 55
    0xfe,0xfe,0xc6,0xb6,0xb2,0x86,0x96,0xb2,0x16,0xc6,0xfe,0xfe,0xfe, // 56
    0xfe,0xfe,0x86,0xb6,0x32,0xb2,0xa2,0xd2,0xb6,0x8e,0xfe,0xfe,0xfe, // 57
    0xfe,0xfe,0xfe,0xfe,0xfe,0x1e,0x3e,0xfe,0x3e,0x1e,0xfe,0xfe,0xfe, // 58
    0xfe,0xfe,0xfe,0xfe,0xfe,0x9e,0x9e,0xfe,0xfe,0x8e,0x1e,0xfe,0xfe, // 59
    0xfe,0xfe,0xfe,0xfe,0xe6,0xe,0x3e,0xe,0xc6,0xfe,0xfe,0xfe,0xfe, // 60
    0xfe,0xfe,0xfe,0xfe,0x6,0x6,0x6,0x6,0xfe,0xfe,0xfe,0xfe,0xfe, // 61
    0xfe,0xfe,0xfe,0xfe,0x1e,0x8e,0xe6,0x86,0x1e,0xfe,0xfe,0xfe,0xfe, // 62
    0xfe,0xfe,0x86,0xa2,0xf2,0xe2,0xce,0xde,0xde,0xce,0xfe,0xfe,0xfe, // 63
    0xfe,0xfe,0xce,0xb6,0xa,0x2,0x16,0x2,0x2,0x6,0xbe,0xce,0xfe, // 64
    0xfe,0xfe,0xee,0xce,0xce,0xe6,0x86,0x86,0xb2,0xb2,0xfe,0xfe,0xfe, // 65
    0xfe,0xfe,0x86,0x92,0xb2,0x82,0x92,0x9a,0x12,0x86,0xfe,0xfe,0xfe, // 66
    0xfe,0xfe,0x86,0xb2,0x3e,0x3e,0x3e,0x3e,0x96,0x86,0xfe,0xfe,0xfe, // 67
    0xfe,0xfe,0x86,0x96,0xb2,0xba,0xb2,0xb2,0x12,0xe,0xfe,0xfe,0xfe, // 68
    0xfe,0xfe,0x82,0x9e,0xb6,0x86,0x86,0xbe,0xe,0x82,0xfe,0xfe,0xfe, // 69
    0xfe,0xfe,0x82,0x9e,0xb6,0x86,0x86,0xbe,0x1e,0x9e,0xfe,0xfe,0xfe, // 70
    0xfe,0xfe,0x86,0xb2,0x3e,0x36,0x32,0x32,0xa2,0x86,0xfe,0xfe,0xfe, // 71
    0xfe,0xfe,0xb2,0x36,0xb2,0x86,0x96,0xb6,0x32,0x36,0xfe,0xfe,0xfe, // 72
    0xfe,0xfe,0x8e,0x86,0x8e,0xce,0xce,0x8e,0x86,0x8e,0xfe,0xfe,0xfe, // 73
    0xfe,0xfe,0xce,0xce,0xce,0xce,0xce,0xce,0xce,0xce,0x4e,0x1e,0xfe, // 74
    0xfe,0xfe,0x96,0xa6,0x8e,0x9e,0x8e,0x8e,0x6,0xb2,0xfe,0xfe,0xfe, // 75
    0xfe,0xfe,0x9e,0x9e,0xbe,0x9e,0x9e,0xbe,0xa,0x82,0xfe,0xfe,0xfe, // 76
    0xfe,0xfe,0x32,0xb6,0x26,0x92,0x86,0x46,0xd2,0x36,0xfe,0xfe,0xfe, // 77
    0xfe,0xfe,0x36,0x96,0x9e,0x16,0xce,0xa6,0x66,0x3e,0xfe,0xfe,0xfe, // 78
    0xfe,0xfe,0x86,0xb2,0x3a,0x38,0x32,0x32,0xb6,0x86,0xfe,0xfe,0xfe, // 79
    0xfe,0xfe,0x86,0x92,0xb2,0x86,0x9e,0x9e,0x1e,0x9e,0xfe,0xfe,0xfe, // 80
    0xfe,0xfe,0x86,0xb2,0x3a,0x38,0x32,0x3a,0x92,0xc6,0xf6,0xfe,0xfe, // 81
    0xfe,0xfe,0x86,0x16,0xb6,0x6,0x86,0xb6,0x12,0xba,0xfe,0xfe,0xfe, // 82
    0xfe,0xfe,0x86,0xb6,0x3e,0x8e,0xc6,0xf6,0x32,0x8e,0xfe,0xfe,0xfe, // 83
    0xfe,0xfe,0x6,0x46,0xde,0xde,0xde,0xde,0x9e,0xce,0xfe,0xfe,0xfe, // 84
    0xfe,0xfe,0x12,0xb6,0xb6,0x36,0xb6,0x36,0x86,0xce,0xfe,0xfe,0xfe, // 85
    0xfe,0xfe,0x92,0x9e,0x96,0xd6,0xce,0xce,0xce,0xee,0xfe,0xfe,0xfe, // 86
    0xfe,0xfe,0x56,0x1e,0x6,0xce,0x8e,0xa6,0xa6,0xae,0xfe,0xfe,0xfe, // 87
    0xfe,0xfe,0x26,0x8e,0x8e,0x9e,0xde,0x8e,0xae,0x26,0xfe,0xfe,0xfe, // 88
    0xfe,0xfe,0x92,0x9e,0xc6,0xce,0xee,0xee,0xee,0xce,0xfe,0xfe,0xfe, // 89
    0xfe,0xfe,0x6,0xe6,0xee,0xce,0xde,0x9e,0x1a,0x6,0xfe,0xfe,0xfe, // 90
    0xfe,0xfe,0x8e,0x9e,0x9e,0x9e,0x1e,0x9e,0x9e,0x9e,0x9e,0x8e,0xfe, // 91
    0xfe,0xfe,0x7e,0x3e,0x3e,0x9e,0x9e,0xde,0xce,0xce,0xfe,0xfe,0xfe, // 92
    0xfe,0xfe,0xce,0xee,0xe6,0xce,0xce,0xee,0xe6,0xee,0xce,0xee,0xfe, // 93
    0xfe,0xfe,0x9e,0x8e,0xb6,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe, // 94
    0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0x6, // 95
    0xfe,0xfe,0x86,0x86,0x86,0xde,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe, // 96
    0xfe,0xfe,0xfe,0xfe,0x8e,0xae,0x86,0x26,0x26,0x86,0xfe,0xfe,0xfe, // 97
    0xfe,0xfe,0x3e,0xbe,0x8e,0x26,0xb6,0xb6,0x26,0xe,0xfe,0xfe,0xfe, // 98
    0xfe,0xfe,0xfe,0xfe,0x8e,0x6,0x3e,0x3e,0x2e,0x8e,0xfe,0xfe,0xfe, // 99
    0xfe,0xfe,0xee,0xee,0x86,0xe,0x6e,0x2e,0x2e,0x86,0xfe,0xfe,0xfe, // 100
    0xfe,0xfe,0xfe,0xfe,0x8e,0xa6,0x6,0x26,0x1e,0x8e,0xfe,0xfe,0xfe, // 101
    0xfe,0xfe,0xce,0xbe,0x1e,0x9e,0xbe,0xbe,0x9e,0x1e,0xfe,0xfe,0xfe, // 102
    0xfe,0xfe,0xfe,0xfe,0x8e,0x86,0x2e,0x2e,0x2e,0x8e,0xee,0xe,0xfe, // 103
    0xfe,0xfe,0x3e,0x3e,0xe,0x8e,0x2e,0xa6,0x26,0x6,0xfe,0xfe,0xfe, // 104
    0xfe,0xfe,0x9e,0xfe,0x1e,0x9e,0x8e,0x9e,0x8e,0x8e,0xfe,0xfe,0xfe, // 105
    0xfe,0xfe,0xce,0xfe,0xce,0xce,0xce,0xce,0xce,0xce,0x4e,0xe,0xfe, // 106
    0xfe,0xfe,0x3e,0xbe,0x2e,0x8e,0x1e,0x1e,0xe,0x86,0xfe,0xfe,0xfe, // 107
    0xfe,0xfe,0x9e,0x9e,0x9e,0x9e,0x9e,0x9e,0x8e,0x9e,0xfe,0xfe,0xfe, // 108
    0xfe,0xfe,0xfe,0xfe,0x6,0x6,0x16,0x6,0x2,0x6,0xfe,0xfe,0xfe, // 109
    0xfe,0xfe,0xfe,0xfe,0xe,0xe,0xae,0x26,0x26,0x6,0xfe,0xfe,0xfe, // 110
    0xfe,0xfe,0xfe,0xfe,0x8e,0x26,0x26,0x26,0x6,0x8e,0xfe,0xfe,0xfe, // 111
    0xfe,0xfe,0xfe,0xfe,0xae,0x6,0xb6,0xb6,0x96,0x8e,0x3e,0xbe,0xfe, // 112
    0xfe,0xfe,0xfe,0xfe,0x8e,0x86,0x2e,0x2e,0x2e,0x8e,0xee,0xc6,0xfe, // 113
    0xfe,0xfe,0xfe,0xfe,0x26,0x86,0xbe,0xbe,0x1e,0x9e,0xfe,0xfe,0xfe, // 114
    0xfe,0xfe,0xfe,0xfe,0x86,0x2e,0x86,0x82,0x22,0x86,0xfe,0xfe,0xfe, // 115
    0xfe,0xfe,0xfe,0x9e,0x1e,0x9e,0x9e,0xbe,0x9e,0x8e,0xfe,0xfe,0xfe, // 116
    0xfe,0xfe,0xfe,0xfe,0x2e,0x2e,0x2e,0xae,0x2e,0x86,0xfe,0xfe,0xfe, // 117
    0xfe,0xfe,0xfe,0xfe,0x92,0x96,0x96,0xce,0xce,0xee,0xfe,0xfe,0xfe, // 118
    0xfe,0xfe,0xfe,0xfe,0x16,0x6,0x6,0x8e,0x86,0xae,0xfe,0xfe,0xfe, // 119
    0xfe,0xfe,0xfe,0xfe,0x2e,0xe,0x8e,0xce,0x8e,0x26,0xfe,0xfe,0xfe, // 120
    0xfe,0xfe,0xfe,0xfe,0x92,0x96,0x96,0xce,0xce,0xee,0xce,0x9e,0xfe, // 121
    0xfe,0xfe,0xfe,0xfe,0x6,0xee,0xce,0x9e,0x9e,0x26,0xfe,0xfe,0xfe, // 122
    0xfe,0xfe,0xce,0xde,0xde,0x9e,0x3e,0x9e,0xde,0x9e,0xde,0xce,0xfe, // 123
    0xfe,0xfe,0x3e,0x3e,0x3e,0x3e,0x3e,0x3e,0x3e,0x3e,0x3e,0x1e,0x7e, // 124
    0xfe,0xfe,0x9e,0x9e,0xde,0x9e,0xce,0xce,0xde,0x9e,0x9e,0x3e,0xfe, // 125
    0xfe,0xfe,0xfe,0xfe,0xfe,0x1e,0x6,0xc6,0xfe,0xfe,0xfe,0xfe,0xfe, // 126
};