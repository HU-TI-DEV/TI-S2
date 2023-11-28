COPY "%1" "..\_slidev\"
CD "..\_slidev\"
for /F %%i in ("%1") do @npx slidev %%~ni