#!/usr/bin/env zsh

target="bsq"
tests_dir="tests"
inputs_dir="${tests_dir}/1_inputs"
expected_dir="${tests_dir}/3_expected"
output_dir="${tests_dir}/4_outputs"

passed=0
failed=0
total=0

rm -r "${output_dir}" || true
mkdir -p "${output_dir}"

for f in "${inputs_dir}"/*; do
	filename="$(basename "$f")"
	input_file="${inputs_dir}/${filename}"
	input="$(cat "${input_file}")"
	expected_file="${expected_dir}/${filename}"
	output_file="${output_dir}/${filename}"

	./"${target}" ${=input} |& cat -e > "${output_file}" 2>&1
	
	if diff -q "${expected_file}" "${output_file}" > /dev/null; then
		((passed++))
	else
		((failed++))
		echo "------------------------------"
		echo
		echo "❌ ./${target} ${input}"
		echo
		echo "⮕ diff ${expected_file} ${output_file}"
		echo
		diff "${expected_file}" "${output_file}"
		echo
		echo "------------------------------"
	fi
	((total++))
done

echo
if (( failed == 0 )); then
	echo "===> ✅ ${passed} / ${total} tests passed"
	exit 0
else
	echo "===> ❌ ${failed} / ${total} tests failed"
	exit 1
fi
