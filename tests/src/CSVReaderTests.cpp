/*
    Copyright (c) 2019 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "CSVReaderTests.h"
#include "Ishiko/CSV/CSVReader.h"

using namespace Ishiko::TestFramework;

void CSVReaderTests::AddTests(TestHarness& theTestHarness)
{
    TestSequence& readerTestSequence = theTestHarness.appendTestSequence("CSVReader tests");

    new HeapAllocationErrorsTest("Creation test 1", CreationTest1, readerTestSequence);
    new HeapAllocationErrorsTest("open test 1", OpenTest1, readerTestSequence);
    new HeapAllocationErrorsTest("readLine test 1", ReadLineTest1, readerTestSequence);
}

TestResult::EOutcome CSVReaderTests::CreationTest1()
{
    Ishiko::CSV::CSVReader reader;
    return TestResult::ePassed;
}

TestResult::EOutcome CSVReaderTests::OpenTest1(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestDataDirectory() / "empty.csv");

    Ishiko::CSV::CSVReader reader;
    reader.open(inputPath);

    return TestResult::ePassed;
}

TestResult::EOutcome CSVReaderTests::ReadLineTest1(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestDataDirectory() / "empty.csv");

    Ishiko::CSV::CSVReader reader;
    reader.open(inputPath);

    reader.readLine();

    return TestResult::eFailed;
}
