for /f %%a in ('dir /b /s /od D:\ÓÃ»§Ä¿Â¼\Downloads\*.in') do set "fn=%%a"
copy "%fn%" input.txt