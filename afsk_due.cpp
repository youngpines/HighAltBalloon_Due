/*
 * From the verbose outputs, Uno (top) vs Due (bottom)
 * 
ARDUINO_AVR_UNO
ARDUINO_SAM_DUE

ARDUINO_ARCH_AVR
ARDUINO_ARCH_SAM


F_CPU=16000000L
F_CPU=84000000L
 * 
 */

#ifdef ARDUINO_SAM_DUE

#include "afsk_due.h"
#include "config.h"

#define DAC_PCT 35 //Percentage of DAC output

extern const uint16_t afsk_sine_table[512] =
   {
        (0 * DAC_PCT / 100) + 2048, (25 * DAC_PCT / 100) + 2048, (50 * DAC_PCT / 100) + 2048,
        (75 * DAC_PCT / 100) + 2048, (100 * DAC_PCT / 100) + 2048, (125 * DAC_PCT / 100) + 2048,
        (150 * DAC_PCT / 100) + 2048, (175 * DAC_PCT / 100) + 2048, (200 * DAC_PCT / 100) + 2048,
        (225 * DAC_PCT / 100) + 2048, (250 * DAC_PCT / 100) + 2048, (275 * DAC_PCT / 100) + 2048,
        (300 * DAC_PCT / 100) + 2048, (325 * DAC_PCT / 100) + 2048, (350 * DAC_PCT / 100) + 2048,
        (374 * DAC_PCT / 100) + 2048, (399 * DAC_PCT / 100) + 2048, (424 * DAC_PCT / 100) + 2048,
        (448 * DAC_PCT / 100) + 2048, (473 * DAC_PCT / 100) + 2048, (497 * DAC_PCT / 100) + 2048,
        (521 * DAC_PCT / 100) + 2048, (546 * DAC_PCT / 100) + 2048, (570 * DAC_PCT / 100) + 2048,
        (594 * DAC_PCT / 100) + 2048, (618 * DAC_PCT / 100) + 2048, (642 * DAC_PCT / 100) + 2048,
        (666 * DAC_PCT / 100) + 2048, (689 * DAC_PCT / 100) + 2048, (713 * DAC_PCT / 100) + 2048,
        (737 * DAC_PCT / 100) + 2048, (760 * DAC_PCT / 100) + 2048, (783 * DAC_PCT / 100) + 2048,
        (806 * DAC_PCT / 100) + 2048, (829 * DAC_PCT / 100) + 2048, (852 * DAC_PCT / 100) + 2048,
        (875 * DAC_PCT / 100) + 2048, (898 * DAC_PCT / 100) + 2048, (920 * DAC_PCT / 100) + 2048,
        (943 * DAC_PCT / 100) + 2048, (965 * DAC_PCT / 100) + 2048, (987 * DAC_PCT / 100) + 2048,
        (1009 * DAC_PCT / 100) + 2048, (1031 * DAC_PCT / 100) + 2048, (1052 * DAC_PCT / 100) + 2048,
        (1074 * DAC_PCT / 100) + 2048, (1095 * DAC_PCT / 100) + 2048, (1116 * DAC_PCT / 100) + 2048,
        (1137 * DAC_PCT / 100) + 2048, (1158 * DAC_PCT / 100) + 2048, (1179 * DAC_PCT / 100) + 2048,
        (1199 * DAC_PCT / 100) + 2048, (1219 * DAC_PCT / 100) + 2048, (1240 * DAC_PCT / 100) + 2048,
        (1259 * DAC_PCT / 100) + 2048, (1279 * DAC_PCT / 100) + 2048, (1299 * DAC_PCT / 100) + 2048,
        (1318 * DAC_PCT / 100) + 2048, (1337 * DAC_PCT / 100) + 2048, (1356 * DAC_PCT / 100) + 2048,
        (1375 * DAC_PCT / 100) + 2048, (1393 * DAC_PCT / 100) + 2048, (1412 * DAC_PCT / 100) + 2048,
        (1430 * DAC_PCT / 100) + 2048, (1448 * DAC_PCT / 100) + 2048, (1465 * DAC_PCT / 100) + 2048,
        (1483 * DAC_PCT / 100) + 2048, (1500 * DAC_PCT / 100) + 2048, (1517 * DAC_PCT / 100) + 2048,
        (1534 * DAC_PCT / 100) + 2048, (1550 * DAC_PCT / 100) + 2048, (1567 * DAC_PCT / 100) + 2048,
        (1583 * DAC_PCT / 100) + 2048, (1598 * DAC_PCT / 100) + 2048, (1614 * DAC_PCT / 100) + 2048,
        (1629 * DAC_PCT / 100) + 2048, (1644 * DAC_PCT / 100) + 2048, (1659 * DAC_PCT / 100) + 2048,
        (1674 * DAC_PCT / 100) + 2048, (1688 * DAC_PCT / 100) + 2048, (1702 * DAC_PCT / 100) + 2048,
        (1716 * DAC_PCT / 100) + 2048, (1730 * DAC_PCT / 100) + 2048, (1743 * DAC_PCT / 100) + 2048,
        (1756 * DAC_PCT / 100) + 2048, (1769 * DAC_PCT / 100) + 2048, (1781 * DAC_PCT / 100) + 2048,
        (1794 * DAC_PCT / 100) + 2048, (1806 * DAC_PCT / 100) + 2048, (1817 * DAC_PCT / 100) + 2048,
        (1829 * DAC_PCT / 100) + 2048, (1840 * DAC_PCT / 100) + 2048, (1851 * DAC_PCT / 100) + 2048,
        (1861 * DAC_PCT / 100) + 2048, (1872 * DAC_PCT / 100) + 2048, (1882 * DAC_PCT / 100) + 2048,
        (1892 * DAC_PCT / 100) + 2048, (1901 * DAC_PCT / 100) + 2048, (1910 * DAC_PCT / 100) + 2048,
        (1919 * DAC_PCT / 100) + 2048, (1928 * DAC_PCT / 100) + 2048, (1936 * DAC_PCT / 100) + 2048,
        (1944 * DAC_PCT / 100) + 2048, (1952 * DAC_PCT / 100) + 2048, (1959 * DAC_PCT / 100) + 2048,
        (1966 * DAC_PCT / 100) + 2048, (1973 * DAC_PCT / 100) + 2048, (1980 * DAC_PCT / 100) + 2048,
        (1986 * DAC_PCT / 100) + 2048, (1992 * DAC_PCT / 100) + 2048, (1998 * DAC_PCT / 100) + 2048,
        (2003 * DAC_PCT / 100) + 2048, (2008 * DAC_PCT / 100) + 2048, (2013 * DAC_PCT / 100) + 2048,
        (2017 * DAC_PCT / 100) + 2048, (2021 * DAC_PCT / 100) + 2048, (2025 * DAC_PCT / 100) + 2048,
        (2029 * DAC_PCT / 100) + 2048, (2032 * DAC_PCT / 100) + 2048, (2035 * DAC_PCT / 100) + 2048,
        (2038 * DAC_PCT / 100) + 2048, (2040 * DAC_PCT / 100) + 2048, (2042 * DAC_PCT / 100) + 2048,
        (2044 * DAC_PCT / 100) + 2048, (2045 * DAC_PCT / 100) + 2048, (2046 * DAC_PCT / 100) + 2048,
        (2047 * DAC_PCT / 100) + 2048, (2047 * DAC_PCT / 100) + 2048, (2047 * DAC_PCT / 100) + 2048,
        (2047 * DAC_PCT / 100) + 2048, (2047 * DAC_PCT / 100) + 2048, (2046 * DAC_PCT / 100) + 2048,
        (2045 * DAC_PCT / 100) + 2048, (2044 * DAC_PCT / 100) + 2048, (2042 * DAC_PCT / 100) + 2048,
        (2040 * DAC_PCT / 100) + 2048, (2038 * DAC_PCT / 100) + 2048, (2035 * DAC_PCT / 100) + 2048,
        (2032 * DAC_PCT / 100) + 2048, (2029 * DAC_PCT / 100) + 2048, (2025 * DAC_PCT / 100) + 2048,
        (2021 * DAC_PCT / 100) + 2048, (2017 * DAC_PCT / 100) + 2048, (2013 * DAC_PCT / 100) + 2048,
        (2008 * DAC_PCT / 100) + 2048, (2003 * DAC_PCT / 100) + 2048, (1998 * DAC_PCT / 100) + 2048,
        (1992 * DAC_PCT / 100) + 2048, (1986 * DAC_PCT / 100) + 2048, (1980 * DAC_PCT / 100) + 2048,
        (1973 * DAC_PCT / 100) + 2048, (1966 * DAC_PCT / 100) + 2048, (1959 * DAC_PCT / 100) + 2048,
        (1952 * DAC_PCT / 100) + 2048, (1944 * DAC_PCT / 100) + 2048, (1936 * DAC_PCT / 100) + 2048,
        (1928 * DAC_PCT / 100) + 2048, (1919 * DAC_PCT / 100) + 2048, (1910 * DAC_PCT / 100) + 2048,
        (1901 * DAC_PCT / 100) + 2048, (1892 * DAC_PCT / 100) + 2048, (1882 * DAC_PCT / 100) + 2048,
        (1872 * DAC_PCT / 100) + 2048, (1861 * DAC_PCT / 100) + 2048, (1851 * DAC_PCT / 100) + 2048,
        (1840 * DAC_PCT / 100) + 2048, (1829 * DAC_PCT / 100) + 2048, (1817 * DAC_PCT / 100) + 2048,
        (1806 * DAC_PCT / 100) + 2048, (1794 * DAC_PCT / 100) + 2048, (1781 * DAC_PCT / 100) + 2048,
        (1769 * DAC_PCT / 100) + 2048, (1756 * DAC_PCT / 100) + 2048, (1743 * DAC_PCT / 100) + 2048,
        (1730 * DAC_PCT / 100) + 2048, (1716 * DAC_PCT / 100) + 2048, (1702 * DAC_PCT / 100) + 2048,
        (1688 * DAC_PCT / 100) + 2048, (1674 * DAC_PCT / 100) + 2048, (1659 * DAC_PCT / 100) + 2048,
        (1644 * DAC_PCT / 100) + 2048, (1629 * DAC_PCT / 100) + 2048, (1614 * DAC_PCT / 100) + 2048,
        (1598 * DAC_PCT / 100) + 2048, (1583 * DAC_PCT / 100) + 2048, (1567 * DAC_PCT / 100) + 2048,
        (1550 * DAC_PCT / 100) + 2048, (1534 * DAC_PCT / 100) + 2048, (1517 * DAC_PCT / 100) + 2048,
        (1500 * DAC_PCT / 100) + 2048, (1483 * DAC_PCT / 100) + 2048, (1465 * DAC_PCT / 100) + 2048,
        (1448 * DAC_PCT / 100) + 2048, (1430 * DAC_PCT / 100) + 2048, (1412 * DAC_PCT / 100) + 2048,
        (1393 * DAC_PCT / 100) + 2048, (1375 * DAC_PCT / 100) + 2048, (1356 * DAC_PCT / 100) + 2048,
        (1337 * DAC_PCT / 100) + 2048, (1318 * DAC_PCT / 100) + 2048, (1299 * DAC_PCT / 100) + 2048,
        (1279 * DAC_PCT / 100) + 2048, (1259 * DAC_PCT / 100) + 2048, (1240 * DAC_PCT / 100) + 2048,
        (1219 * DAC_PCT / 100) + 2048, (1199 * DAC_PCT / 100) + 2048, (1179 * DAC_PCT / 100) + 2048,
        (1158 * DAC_PCT / 100) + 2048, (1137 * DAC_PCT / 100) + 2048, (1116 * DAC_PCT / 100) + 2048,
        (1095 * DAC_PCT / 100) + 2048, (1074 * DAC_PCT / 100) + 2048, (1052 * DAC_PCT / 100) + 2048,
        (1031 * DAC_PCT / 100) + 2048, (1009 * DAC_PCT / 100) + 2048, (987 * DAC_PCT / 100) + 2048,
        (965 * DAC_PCT / 100) + 2048, (943 * DAC_PCT / 100) + 2048, (920 * DAC_PCT / 100) + 2048,
        (898 * DAC_PCT / 100) + 2048, (875 * DAC_PCT / 100) + 2048, (852 * DAC_PCT / 100) + 2048,
        (829 * DAC_PCT / 100) + 2048, (806 * DAC_PCT / 100) + 2048, (783 * DAC_PCT / 100) + 2048,
        (760 * DAC_PCT / 100) + 2048, (737 * DAC_PCT / 100) + 2048, (713 * DAC_PCT / 100) + 2048,
        (689 * DAC_PCT / 100) + 2048, (666 * DAC_PCT / 100) + 2048, (642 * DAC_PCT / 100) + 2048,
        (618 * DAC_PCT / 100) + 2048, (594 * DAC_PCT / 100) + 2048, (570 * DAC_PCT / 100) + 2048,
        (546 * DAC_PCT / 100) + 2048, (521 * DAC_PCT / 100) + 2048, (497 * DAC_PCT / 100) + 2048,
        (473 * DAC_PCT / 100) + 2048, (448 * DAC_PCT / 100) + 2048, (424 * DAC_PCT / 100) + 2048,
        (399 * DAC_PCT / 100) + 2048, (374 * DAC_PCT / 100) + 2048, (350 * DAC_PCT / 100) + 2048,
        (325 * DAC_PCT / 100) + 2048, (300 * DAC_PCT / 100) + 2048, (275 * DAC_PCT / 100) + 2048,
        (250 * DAC_PCT / 100) + 2048, (225 * DAC_PCT / 100) + 2048, (200 * DAC_PCT / 100) + 2048,
        (175 * DAC_PCT / 100) + 2048, (150 * DAC_PCT / 100) + 2048, (125 * DAC_PCT / 100) + 2048,
        (100 * DAC_PCT / 100) + 2048, (75 * DAC_PCT / 100) + 2048, (50 * DAC_PCT / 100) + 2048,
        (25 * DAC_PCT / 100) + 2048, (0 * DAC_PCT / 100) + 2048, (-25 * DAC_PCT / 100) + 2048,
        (-50 * DAC_PCT / 100) + 2048, (-75 * DAC_PCT / 100) + 2048, (-100 * DAC_PCT / 100) + 2048,
        (-125 * DAC_PCT / 100) + 2048, (-150 * DAC_PCT / 100) + 2048, (-175 * DAC_PCT / 100) + 2048,
        (-200 * DAC_PCT / 100) + 2048, (-225 * DAC_PCT / 100) + 2048, (-250 * DAC_PCT / 100) + 2048,
        (-275 * DAC_PCT / 100) + 2048, (-300 * DAC_PCT / 100) + 2048, (-325 * DAC_PCT / 100) + 2048,
        (-350 * DAC_PCT / 100) + 2048, (-374 * DAC_PCT / 100) + 2048, (-399 * DAC_PCT / 100) + 2048,
        (-424 * DAC_PCT / 100) + 2048, (-448 * DAC_PCT / 100) + 2048, (-473 * DAC_PCT / 100) + 2048,
        (-497 * DAC_PCT / 100) + 2048, (-521 * DAC_PCT / 100) + 2048, (-546 * DAC_PCT / 100) + 2048,
        (-570 * DAC_PCT / 100) + 2048, (-594 * DAC_PCT / 100) + 2048, (-618 * DAC_PCT / 100) + 2048,
        (-642 * DAC_PCT / 100) + 2048, (-666 * DAC_PCT / 100) + 2048, (-689 * DAC_PCT / 100) + 2048,
        (-713 * DAC_PCT / 100) + 2048, (-737 * DAC_PCT / 100) + 2048, (-760 * DAC_PCT / 100) + 2048,
        (-783 * DAC_PCT / 100) + 2048, (-806 * DAC_PCT / 100) + 2048, (-829 * DAC_PCT / 100) + 2048,
        (-852 * DAC_PCT / 100) + 2048, (-875 * DAC_PCT / 100) + 2048, (-898 * DAC_PCT / 100) + 2048,
        (-920 * DAC_PCT / 100) + 2048, (-943 * DAC_PCT / 100) + 2048, (-965 * DAC_PCT / 100) + 2048,
        (-987 * DAC_PCT / 100) + 2048, (-1009 * DAC_PCT / 100) + 2048, (-1031 * DAC_PCT / 100) + 2048,
        (-1052 * DAC_PCT / 100) + 2048, (-1074 * DAC_PCT / 100) + 2048, (-1095 * DAC_PCT / 100) + 2048,
        (-1116 * DAC_PCT / 100) + 2048, (-1137 * DAC_PCT / 100) + 2048, (-1158 * DAC_PCT / 100) + 2048,
        (-1179 * DAC_PCT / 100) + 2048, (-1199 * DAC_PCT / 100) + 2048, (-1219 * DAC_PCT / 100) + 2048,
        (-1240 * DAC_PCT / 100) + 2048, (-1259 * DAC_PCT / 100) + 2048, (-1279 * DAC_PCT / 100) + 2048,
        (-1299 * DAC_PCT / 100) + 2048, (-1318 * DAC_PCT / 100) + 2048, (-1337 * DAC_PCT / 100) + 2048,
        (-1356 * DAC_PCT / 100) + 2048, (-1375 * DAC_PCT / 100) + 2048, (-1393 * DAC_PCT / 100) + 2048,
        (-1412 * DAC_PCT / 100) + 2048, (-1430 * DAC_PCT / 100) + 2048, (-1448 * DAC_PCT / 100) + 2048,
        (-1465 * DAC_PCT / 100) + 2048, (-1483 * DAC_PCT / 100) + 2048, (-1500 * DAC_PCT / 100) + 2048,
        (-1517 * DAC_PCT / 100) + 2048, (-1534 * DAC_PCT / 100) + 2048, (-1550 * DAC_PCT / 100) + 2048,
        (-1567 * DAC_PCT / 100) + 2048, (-1583 * DAC_PCT / 100) + 2048, (-1598 * DAC_PCT / 100) + 2048,
        (-1614 * DAC_PCT / 100) + 2048, (-1629 * DAC_PCT / 100) + 2048, (-1644 * DAC_PCT / 100) + 2048,
        (-1659 * DAC_PCT / 100) + 2048, (-1674 * DAC_PCT / 100) + 2048, (-1688 * DAC_PCT / 100) + 2048,
        (-1702 * DAC_PCT / 100) + 2048, (-1716 * DAC_PCT / 100) + 2048, (-1730 * DAC_PCT / 100) + 2048,
        (-1743 * DAC_PCT / 100) + 2048, (-1756 * DAC_PCT / 100) + 2048, (-1769 * DAC_PCT / 100) + 2048,
        (-1781 * DAC_PCT / 100) + 2048, (-1794 * DAC_PCT / 100) + 2048, (-1806 * DAC_PCT / 100) + 2048,
        (-1817 * DAC_PCT / 100) + 2048, (-1829 * DAC_PCT / 100) + 2048, (-1840 * DAC_PCT / 100) + 2048,
        (-1851 * DAC_PCT / 100) + 2048, (-1861 * DAC_PCT / 100) + 2048, (-1872 * DAC_PCT / 100) + 2048,
        (-1882 * DAC_PCT / 100) + 2048, (-1892 * DAC_PCT / 100) + 2048, (-1901 * DAC_PCT / 100) + 2048,
        (-1910 * DAC_PCT / 100) + 2048, (-1919 * DAC_PCT / 100) + 2048, (-1928 * DAC_PCT / 100) + 2048,
        (-1936 * DAC_PCT / 100) + 2048, (-1944 * DAC_PCT / 100) + 2048, (-1952 * DAC_PCT / 100) + 2048,
        (-1959 * DAC_PCT / 100) + 2048, (-1966 * DAC_PCT / 100) + 2048, (-1973 * DAC_PCT / 100) + 2048,
        (-1980 * DAC_PCT / 100) + 2048, (-1986 * DAC_PCT / 100) + 2048, (-1992 * DAC_PCT / 100) + 2048,
        (-1998 * DAC_PCT / 100) + 2048, (-2003 * DAC_PCT / 100) + 2048, (-2008 * DAC_PCT / 100) + 2048,
        (-2013 * DAC_PCT / 100) + 2048, (-2017 * DAC_PCT / 100) + 2048, (-2021 * DAC_PCT / 100) + 2048,
        (-2025 * DAC_PCT / 100) + 2048, (-2029 * DAC_PCT / 100) + 2048, (-2032 * DAC_PCT / 100) + 2048,
        (-2035 * DAC_PCT / 100) + 2048, (-2038 * DAC_PCT / 100) + 2048, (-2040 * DAC_PCT / 100) + 2048,
        (-2042 * DAC_PCT / 100) + 2048, (-2044 * DAC_PCT / 100) + 2048, (-2045 * DAC_PCT / 100) + 2048,
        (-2046 * DAC_PCT / 100) + 2048, (-2047 * DAC_PCT / 100) + 2048, (-2047 * DAC_PCT / 100) + 2048,
        (-2047 * DAC_PCT / 100) + 2048, (-2047 * DAC_PCT / 100) + 2048, (-2047 * DAC_PCT / 100) + 2048,
        (-2046 * DAC_PCT / 100) + 2048, (-2045 * DAC_PCT / 100) + 2048, (-2044 * DAC_PCT / 100) + 2048,
        (-2042 * DAC_PCT / 100) + 2048, (-2040 * DAC_PCT / 100) + 2048, (-2038 * DAC_PCT / 100) + 2048,
        (-2035 * DAC_PCT / 100) + 2048, (-2032 * DAC_PCT / 100) + 2048, (-2029 * DAC_PCT / 100) + 2048,
        (-2025 * DAC_PCT / 100) + 2048, (-2021 * DAC_PCT / 100) + 2048, (-2017 * DAC_PCT / 100) + 2048,
        (-2013 * DAC_PCT / 100) + 2048, (-2008 * DAC_PCT / 100) + 2048, (-2003 * DAC_PCT / 100) + 2048,
        (-1998 * DAC_PCT / 100) + 2048, (-1992 * DAC_PCT / 100) + 2048, (-1986 * DAC_PCT / 100) + 2048,
        (-1980 * DAC_PCT / 100) + 2048, (-1973 * DAC_PCT / 100) + 2048, (-1966 * DAC_PCT / 100) + 2048,
        (-1959 * DAC_PCT / 100) + 2048, (-1952 * DAC_PCT / 100) + 2048, (-1944 * DAC_PCT / 100) + 2048,
        (-1936 * DAC_PCT / 100) + 2048, (-1928 * DAC_PCT / 100) + 2048, (-1919 * DAC_PCT / 100) + 2048,
        (-1910 * DAC_PCT / 100) + 2048, (-1901 * DAC_PCT / 100) + 2048, (-1892 * DAC_PCT / 100) + 2048,
        (-1882 * DAC_PCT / 100) + 2048, (-1872 * DAC_PCT / 100) + 2048, (-1861 * DAC_PCT / 100) + 2048,
        (-1851 * DAC_PCT / 100) + 2048, (-1840 * DAC_PCT / 100) + 2048, (-1829 * DAC_PCT / 100) + 2048,
        (-1817 * DAC_PCT / 100) + 2048, (-1806 * DAC_PCT / 100) + 2048, (-1794 * DAC_PCT / 100) + 2048,
        (-1781 * DAC_PCT / 100) + 2048, (-1769 * DAC_PCT / 100) + 2048, (-1756 * DAC_PCT / 100) + 2048,
        (-1743 * DAC_PCT / 100) + 2048, (-1730 * DAC_PCT / 100) + 2048, (-1716 * DAC_PCT / 100) + 2048,
        (-1702 * DAC_PCT / 100) + 2048, (-1688 * DAC_PCT / 100) + 2048, (-1674 * DAC_PCT / 100) + 2048,
        (-1659 * DAC_PCT / 100) + 2048, (-1644 * DAC_PCT / 100) + 2048, (-1629 * DAC_PCT / 100) + 2048,
        (-1614 * DAC_PCT / 100) + 2048, (-1598 * DAC_PCT / 100) + 2048, (-1583 * DAC_PCT / 100) + 2048,
        (-1567 * DAC_PCT / 100) + 2048, (-1550 * DAC_PCT / 100) + 2048, (-1534 * DAC_PCT / 100) + 2048,
        (-1517 * DAC_PCT / 100) + 2048, (-1500 * DAC_PCT / 100) + 2048, (-1483 * DAC_PCT / 100) + 2048,
        (-1465 * DAC_PCT / 100) + 2048, (-1448 * DAC_PCT / 100) + 2048, (-1430 * DAC_PCT / 100) + 2048,
        (-1412 * DAC_PCT / 100) + 2048, (-1393 * DAC_PCT / 100) + 2048, (-1375 * DAC_PCT / 100) + 2048,
        (-1356 * DAC_PCT / 100) + 2048, (-1337 * DAC_PCT / 100) + 2048, (-1318 * DAC_PCT / 100) + 2048,
        (-1299 * DAC_PCT / 100) + 2048, (-1279 * DAC_PCT / 100) + 2048, (-1259 * DAC_PCT / 100) + 2048,
        (-1240 * DAC_PCT / 100) + 2048, (-1219 * DAC_PCT / 100) + 2048, (-1199 * DAC_PCT / 100) + 2048,
        (-1179 * DAC_PCT / 100) + 2048, (-1158 * DAC_PCT / 100) + 2048, (-1137 * DAC_PCT / 100) + 2048,
        (-1116 * DAC_PCT / 100) + 2048, (-1095 * DAC_PCT / 100) + 2048, (-1074 * DAC_PCT / 100) + 2048,
        (-1052 * DAC_PCT / 100) + 2048, (-1031 * DAC_PCT / 100) + 2048, (-1009 * DAC_PCT / 100) + 2048,
        (-987 * DAC_PCT / 100) + 2048, (-965 * DAC_PCT / 100) + 2048, (-943 * DAC_PCT / 100) + 2048,
        (-920 * DAC_PCT / 100) + 2048, (-898 * DAC_PCT / 100) + 2048, (-875 * DAC_PCT / 100) + 2048,
        (-852 * DAC_PCT / 100) + 2048, (-829 * DAC_PCT / 100) + 2048, (-806 * DAC_PCT / 100) + 2048,
        (-783 * DAC_PCT / 100) + 2048, (-760 * DAC_PCT / 100) + 2048, (-737 * DAC_PCT / 100) + 2048,
        (-713 * DAC_PCT / 100) + 2048, (-689 * DAC_PCT / 100) + 2048, (-666 * DAC_PCT / 100) + 2048,
        (-642 * DAC_PCT / 100) + 2048, (-618 * DAC_PCT / 100) + 2048, (-594 * DAC_PCT / 100) + 2048,
        (-570 * DAC_PCT / 100) + 2048, (-546 * DAC_PCT / 100) + 2048, (-521 * DAC_PCT / 100) + 2048,
        (-497 * DAC_PCT / 100) + 2048, (-473 * DAC_PCT / 100) + 2048, (-448 * DAC_PCT / 100) + 2048,
        (-424 * DAC_PCT / 100) + 2048, (-399 * DAC_PCT / 100) + 2048, (-374 * DAC_PCT / 100) + 2048,
        (-350 * DAC_PCT / 100) + 2048, (-325 * DAC_PCT / 100) + 2048, (-300 * DAC_PCT / 100) + 2048,
        (-275 * DAC_PCT / 100) + 2048, (-250 * DAC_PCT / 100) + 2048, (-225 * DAC_PCT / 100) + 2048,
        (-200 * DAC_PCT / 100) + 2048, (-175 * DAC_PCT / 100) + 2048, (-150 * DAC_PCT / 100) + 2048,
        (-125 * DAC_PCT / 100) + 2048, (-100 * DAC_PCT / 100) + 2048, (-75 * DAC_PCT / 100) + 2048,
        (-50 * DAC_PCT / 100) + 2048, (-25 * DAC_PCT / 100) + 2048
   };

 //External constants
 extern const uint32_t MODEM_CLOCK_RATE = F_CPU; //84 MHz for Due
 extern const uint16_t TABLE_SIZE = sizeof(afsk_sine_table) / sizeof(uint16_t);

 //Exported functions
 //Other tabs with AVR & PIC don't have arguements to pass through
 //Going to allow for some more customization for choosing Timer & Channel because we can
void afsk_timer_setup(Tc *tc, uint32_t channel, IRQn_Type irq, uint32_t freq) {
  //turn off write protection for Power Management Controller (PMC)
  //enable peripheral clock for TC1 Channel 3
  pmc_set_writeprotect(false);
  pmc_enable_periph_clk(ID_TC3); //can use TC3_IRQn for ID_TC3

  //List of options are TC1 = MCK/2 = 42 MHz
  //TC2 = MCK/8 = 10.5 MHz
  //TC3 = MCK/32 = 2.625 MHz
  //TC4 = MCK/128 = 0.65625 MHz
  //Using Timer Clock 1 (master clock / 2 = 42 MHz)
  //function takes TC & Channel as 1st 2 parameters, last to set bits for Waveform mode,
  //only counting to max value in Register C (RC) & which of 5 clocks to use
  TC_Configure(tc, channel, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK1);
  
  //Register C set to max count specified by clock frequency divided by desired frequency
  extern const uint32_t SAMPLES_PER_BAUD;
  uint32_t rc = (VARIANT_MCK / 2 / SAMPLES_PER_BAUD / freq) - 1; //VARIANT_MCK = 84 MHz
  TC_SetRC(tc, channel, rc);

  //Enabling Register C (RC) compare interrupt
  tc -> TC_CHANNEL[channel].TC_IER = TC_IER_CPCS;
  tc -> TC_CHANNEL[channel].TC_IDR = ~TC_IER_CPCS;

  //tell Nested Interrupt Controller to enable IRQ
  NVIC_EnableIRQ(irq);

  //TODO intiailize to 2048
}

void afsk_timer_start(Tc *tc, uint32_t channel) {
  //TODO - Check what this does on scope & see if this resets the count
  //Start timer again
  TC_Start(tc, channel);
}

void afsk_timer_stop(Tc *tc, uint32_t channel) {
  TC_Stop(tc, channel);
}

#endif //#ifdef SAM
