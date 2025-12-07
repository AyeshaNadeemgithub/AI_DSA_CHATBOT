# build_tests.ps1 — compile tests in workspace/tests/ against AI_DSA_CHATBOT sources
# Usage: .\build_tests.ps1

$root = Split-Path -Parent $MyInvocation.MyCommand.Definition
$repoDir = Join-Path $root 'AI_DSA_CHATBOT'
$includeDir = Join-Path $repoDir 'include'
$trieSrc = Join-Path $repoDir 'src/dsa/Trie.cpp'
$testsDir = Join-Path $root 'tests'

if (-not (Test-Path $testsDir)) {
    Write-Error "Tests directory not found: $testsDir"
    exit 1
}

$tests = Get-ChildItem -Path $testsDir -Filter *.cpp -File -ErrorAction SilentlyContinue
if ($tests.Count -eq 0) {
    Write-Error "No test .cpp files found in $testsDir"
    exit 1
}

foreach ($test in $tests) {
    $exe = [System.IO.Path]::ChangeExtension($test.FullName, '.exe')
    $cmd = "g++ `"$($test.FullName)`" `"$trieSrc`" -I`"$includeDir`" -o `"$exe`""
    Write-Host "Compiling: $($test.Name) -> $([System.IO.Path]::GetFileName($exe))"
    Write-Host $cmd
    $proc = Start-Process -FilePath cmd.exe -ArgumentList "/c", $cmd -NoNewWindow -Wait -PassThru
    if ($proc.ExitCode -ne 0) {
        Write-Error "Build failed for $($test.Name) (exit $($proc.ExitCode))"
        exit $proc.ExitCode
    }

    Write-Host "Running: $([System.IO.Path]::GetFileName($exe))"
    & $exe
}
