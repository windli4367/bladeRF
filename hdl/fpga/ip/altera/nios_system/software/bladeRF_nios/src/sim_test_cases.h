/* This file is part of the bladeRF project:
 *   http://www.github.com/nuand/bladeRF
 *
 * Copyright (c) 2015 Nuand LLC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef SIM_TEST_CASES_H_
#define SIM_TEST_CASES_H_

#ifdef BLADERF_NIOS_PC_SIMULATION

struct test_case {
    const char *desc;
    const uint8_t req[NIOS_PKT_LEN];
    const uint8_t resp[NIOS_PKT_LEN];
};

static const struct test_case test_cases[] = {
    {
        .desc = "Garbage input. Should yield no output.",
        .req = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    },

    {
        .desc = "Legacy read from LMS6[0x2f]",
        .req =  { 0x4e, 0x91, 0x2f, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x91, 0x2f, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy write to LMS6[0x07] <- 0x09",
        .req =  { 0x4e, 0x51, 0x07, 0x09, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x51, 0x07, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy read from Si5338[0x03]",
        .req  = { 0x4e, 0xb1, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0xb1, 0x03, 0x88, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy write to Si5338[0x05] <- 0xab",
        .req  = { 0x4e, 0x71, 0x05, 0xab, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x71, 0x05, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy config register read, access 1/4",
        .req  = { 0x4e, 0x81, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x00, 0x57, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy config register read, access 2/4",
        .req  = { 0x4e, 0x81, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x01, 0xde, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy config register read, access 3/4",
        .req  = { 0x4e, 0x81, 0x02, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x02, 0xbc, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
       .desc = "Legacy config register read, access 4/4",
       .req  = { 0x4e, 0x81, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
       .resp = { 0x4e, 0x81, 0x03, 0x8a, 0xff, 0xff, 0xff, 0xff,
                 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
       .desc = "Legacy config register write, access 1/4",
       .req  = { 0x4e, 0x41, 0x00, 0x57, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
       .resp = { 0x4e, 0x41, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
                 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
       .desc = "Legacy config register write, access 2/4",
       .req  = { 0x4e, 0x41, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
       .resp = { 0x4e, 0x41, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff,
                 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
       .desc = "Legacy config register write, access 3/4",
       .req  = { 0x4e, 0x41, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
       .resp = { 0x4e, 0x41, 0x02, 0x00, 0xff, 0xff, 0xff, 0xff,
                 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
       .desc = "Legacy config register write, access 4/4",
       .req  = { 0x4e, 0x41, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
       .resp = { 0x4e, 0x41, 0x03, 0x00, 0xff, 0xff, 0xff, 0xff,
                 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy read of RX IQ gain correction 1/2",
        .req  = { 0x4e, 0x81, 0x04, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x00, 0xd2, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },

    },

    {
        .desc = "Legacy read of RX IQ gain correction 2/2",
        .req  = { 0x4e, 0x81, 0x05, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x01, 0x14, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy write of RX IQ gain correction 1/2",
        .req  = { 0x4e, 0x41, 0x04, 0xd2, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy write of RX IQ gain correction 2/2",
        .req  = { 0x4e, 0x41, 0x05, 0x14, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy read of RX IQ phase correction 1/2",
        .req  = { 0x4e, 0x81, 0x06, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x00, 0x1c, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy read of RX IQ phase correction 2/2",
        .req  = { 0x4e, 0x81, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x01, 0x10, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
   },

    {
        .desc = "Legacy write of RX IQ phase correction 1/2",
        .req  = { 0x4e, 0x41, 0x06, 0x1c, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy write of RX IQ phase correction 2/2",
        .req  = { 0x4e, 0x41, 0x07, 0x10, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy read of TX IQ gain correction 1/2",
        .req  = { 0x4e, 0x81, 0x08, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x00, 0x12, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },

    },

    {
        .desc = "Legacy read of TX IQ gain correction 2/2",
        .req  = { 0x4e, 0x81, 0x09, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x01, 0x08, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy write of TX IQ gain correction 1/2",
        .req  = { 0x4e, 0x41, 0x08, 0x12, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy write of TX IQ gain correction 2/2",
        .req  = { 0x4e, 0x41, 0x09, 0x08, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy read of TX IQ phase correction 1/2",
        .req  = { 0x4e, 0x81, 0x0a, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy read of TX IQ phase correction 2/2",
        .req  = { 0x4e, 0x81, 0x0b, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy write of TX IQ phase correction 1/2",
        .req  = { 0x4e, 0x41, 0x0a, 0x1f, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy write of TX IQ phase correction 2/2",
        .req  = { 0x4e, 0x41, 0x0b, 0x02, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy read of FPGA version 1/4",
        .req  = { 0x4e, 0x81, 0x0c, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x00, FPGA_VERSION_MAJOR & 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy read of FPGA version 2/4",
        .req  = { 0x4e, 0x81, 0x0d, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x01, FPGA_VERSION_MINOR & 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy read of FPGA version 3/4",
        .req  = { 0x4e, 0x81, 0x0e, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x02, FPGA_VERSION_PATCH & 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy read of FPGA version 4/4",
        .req  = { 0x4e, 0x81, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x03, (FPGA_VERSION_PATCH >> 8) & 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff },
    },

#if 0
    /* Invalid, Partial Legacy FPGA version # write attempt 1/4.
     * A write to this address has no effect, but would required 4 writes to
     * complete.  Only 1 of 4 writes is done to exercise the config
     * state machine resetting on a partial read. */
    {
        .desc = "Legacy FPGA version (illegal) write attempt  1/4",
        .req  = { 0x4e, 0x41, 0x0c, 0x01, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

        .resp = { 0x4e, 0x41, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },
#endif

    /* TODO: Legacy RX and TX timestamps reads */


    {
        .desc = "VCTCXO trim dac write 1/2",
        .req  = { 0x4e, 0x41, 0x22, 0x12, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "VCTCXO trim dac write 2/2",
        .req  = { 0x4e, 0x41, 0x23, 0x80, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy XB-200 synth write 1/4",
        .req  = { 0x4e, 0x41, 0x24, 0x05, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy XB-200 synth write 2/4",
        .req  = { 0x4e, 0x41, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy XB-200 synth write 3/4",
        .req  = { 0x4e, 0x41, 0x26, 0x58, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x02, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy XB-200 synth write 4/4",
        .req  = { 0x4e, 0x41, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x03, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {   .desc = "Legacy expansion port read 1/4",
        .req  = { 0x4e, 0x81, 0x28, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy expansion port read 2/4",
        .req  = { 0x4e, 0x81, 0x29, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x01, 0xc7, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy expansion port read 3/4",
        .req  = { 0x4e, 0x81, 0x2a, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy expansion port read 4/4",
        .req  = { 0x4e, 0x81, 0x2b, 0xff, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x81, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy expansion port write 1/4",
        .req  = { 0x4e, 0x41, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy expansion port write 2/4",
        .req  = { 0x4e, 0x41, 0x29, 0x08, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy expansion port write 3/4",
        .req  = { 0x4e, 0x41, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x02, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy expansion port write 4/4",
        .req  = { 0x4e, 0x41, 0x2b, 0x3c, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x03, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    /* TODO: Legacy expansion port direction read */
    {
        .desc = "Legacy expansion port direction read 1/4",
        .req  = { 0x4e, 0x41, 0x2c, 0x3e, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy expansion port direction read 2/4",
        .req  = { 0x4e, 0x41, 0x2d, 0x38, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy expansion port direction read 3/4",
        .req  = { 0x4e, 0x41, 0x2e, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x02, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    },

    {
        .desc = "Legacy expansion port direction read 4/4",
        .req  = { 0x4e, 0x41, 0x2f, 0x3c, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        .resp = { 0x4e, 0x41, 0x03, 0x00, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
    }

  };


#endif

#endif
