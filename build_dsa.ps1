# build_dsa.ps1 — compile individual or all files under AI_DSA_CHATBOT/src/dsa with correct include
# Usage:
#   .\build_dsa.ps1 KMP.cpp        # compile single file
#   .\build_dsa.ps1                # compile all .cpp files in src/dsa

$root = Split-Path -Parent $MyInvocation.MyCommand.Definition
$srcDir = Join-Path $root 'AI_DSA_CHATBOT\src\dsa'
$includeDir = Join-Path $root 'AI_DSA_CHATBOT\include'

param(
    [string]$file
)

if ($file) {
    $srcFiles = @(Join-Path $srcDir $file)
} else {
    $srcFiles = Get-ChildItem -Path $srcDir -Filter *.cpp -File | ForEach-Object { $_.FullName }
}

foreach ($src in $srcFiles) {
    if (-not (Test-Path $src)) {
        Write-Error "Source file not found: $src"
        exit 1
    }
}

foreach ($src in $srcFiles) {
    # Compile to object file to avoid linking when no main() exists
    $obj = [System.IO.Path]::ChangeExtension($src, '.o')
    $cmd = "g++ -c `"$src`" -I`"$includeDir`" -o `"$obj`""
    Write-Host "Compiling (object): $([System.IO.Path]::GetFileName($src)) -> $([System.IO.Path]::GetFileName($obj))"
    $proc = Start-Process -FilePath cmd.exe -ArgumentList "/c", $cmd -NoNewWindow -Wait -PassThru
    if ($proc.ExitCode -ne 0) {
        Write-Error "Build failed for $src (exit $($proc.ExitCode))"
        exit $proc.ExitCode
    }
    Write-Host "Built object: $obj"
}

Write-Host "Done. Object files placed next to sources (use a linker step to create executables)."