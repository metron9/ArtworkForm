
qDebug() << "Executing windows code";
BOOL     bStatus = FALSE;
DOC_INFO_1 DocInfo;
DWORD      dwJob = 0L;
DWORD      dwBytesWritten = 0L;
HANDLE     hPrinter;
wchar_t * name = new wchar_t[this->m_printer_path.length()+1];
this->m_printer_path.toWCharArray(name);
name[this->m_printer_path.length() + 1] = 0;
qDebug() << "opening printer";
bStatus = OpenPrinter(name,&hPrinter, NULL);

if (bStatus) {
    qDebug() << "Printer opened";
    DocInfo.pDocName = L"My Document";
    DocInfo.pOutputFile = NULL;
    DocInfo.pDatatype = L"RAW";
    dwJob = StartDocPrinter( hPrinter, 1, (LPBYTE)&DocInfo );
    if (dwJob > 0) {
        qDebug() << "Job is set.";
        bStatus = StartPagePrinter(hPrinter);
        if (bStatus) {
            qDebug() << "Writing text to printer";
            bStatus = WritePrinter(hPrinter,ba.data(),ba.length(),&dwBytesWritten);
            EndPagePrinter(hPrinter);
        } else {
            qDebug() << "could not start printer";
        }
        EndDocPrinter(hPrinter);
        qDebug() << "closing doc";
    } else {
        qDebug() << "Couldn't create job";
    }
    ClosePrinter(hPrinter);
    qDebug() << "closing printer";
} else {
    qDebug() << "Could not open printer";
}
if (dwBytesWritten != ba.length()) {
    qDebug() << "Wrong number of bytes";
} else {
    qDebug() << "bytes written is correct " << QString::number(ba.length()) ;
}
