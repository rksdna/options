/*
 * Options - processing command line arguments
 * Copyright (c) 2016 Andrey Skrypka
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

#include <stdio.h>
#include "errors.h"
#include "options.h"

static int alpha_handler(void)
{
    fprintf(stdout, "Alpha...");
    return DONE;
}

static int beta_handler(void)
{
    fprintf(stdout, "Beta...");
    return DONE;
}

static int gamma_handler(void)
{
    fprintf(stdout, "Gamma...");

    if (!fopen("invalid file", "r"))
        return INTERNAL_ERROR;

    return DONE;
}

static int delta_handler(const char *arg)
{
    fprintf(stdout, "Delta \"%s\"...", arg);
    return DONE;
}

static int epsilon_handler(const char *arg)
{
    fprintf(stdout, "Epsilon \"%s\"...", arg);
    return CUSTOM_1_ERROR;
}

static int zeta_handler(const char *arg)
{
    fprintf(stdout, "Zeta \"%s\"...", arg);
    return CUSTOM_2_ERROR;
}

static int file_handler(const char *arg)
{
    fprintf(stdout, "File \"%s\" processing...", arg);
    return DONE;
}

int main(int argc, char* argv[])
{
    static const struct option options[] =
    {
        {PLAIN_OPTION, "a", "alpha", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.", alpha_handler},
        {PLAIN_OPTION, 0, "beta", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.", beta_handler},
        {PLAIN_OPTION, "g", 0, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.", gamma_handler},
        {JOINT_OPTION, "d", "delta", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.", delta_handler},
        {JOINT_OPTION, 0, "epsilon", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.", epsilon_handler},
        {JOINT_OPTION, "z", 0, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.", zeta_handler},
        {USAGE_OPTION, "h", "help", "Print this help", usage_options},
        {OTHER_OPTION, 0, 0, 0, file_handler} // Must be at end, set null handler if not needed
    };

    static const struct error errors[] =
    {
        {CUSTOM_2_ERROR, "Description of custom error 2"},
        {CUSTOM_1_ERROR, "Description of custom error 1"},
        {INTERNAL_ERROR, 0}, // Not needed, strerror() substituted
        {INVALID_OPTION, "Invalid option"},
        {DONE, "No errors, all done"}, // Must be at end
    };

    static char stdout_buffer[256];
    setvbuf(stdout, stdout_buffer, _IOLBF, sizeof(stdout_buffer));
    fprintf(stdout, TTY_NONE "Option, version 1.00\n");

    return invoke_options(TTY_BOLD "option" TTY_NONE " [" TTY_UNLN "OPTIONS" TTY_NONE "] " TTY_UNLN "FILES" TTY_NONE, options, errors, argc, argv);
}
