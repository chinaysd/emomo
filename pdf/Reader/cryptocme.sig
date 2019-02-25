<?rsa version="1.0" encoding="utf-8"?>
<Configuration>
	<Product Id="Crypto-C ME">
		<Version>4.0.0.0</Version>
		<ReleaseDate>Jul 01 2011 11:49:55</ReleaseDate>
		<ExpDate>""</ExpDate>
		<Copyright>
			Copyright (C) RSA
		</Copyright>
		<Library Id="master">cryptocme</Library>
	</Product>
	<Runtime Id="runtime">
		<StartupConfig>
			<SelfTest>OnLoad</SelfTest>
		</StartupConfig>
		<LoadOrder>
			<Library Id="ccme_base">ccme_base</Library>
			<Library Id="ccme_base_non_fips">ccme_base_non_fips</Library>
			<Library Id="ccme_asym">ccme_asym</Library>
			<Library Id="ccme_ecc">ccme_ecc</Library>
			<Library Id="ccme_ecc_non_fips">ccme_ecc_non_fips</Library>
			<Library Id="ccme_ecdrbg">ccme_ecdrbg</Library>
			<Library Id="ccme_ecc_accel_fips">ccme_ecc_accel_fips</Library>
			<Library Id="ccme_ecc_accel_non_fips">ccme_ecc_accel_non_fips</Library>
			<Library Id="ccme_error_info">ccme_error_info</Library>
		</LoadOrder>
	</Runtime>
	<Signature URI="#ccme_base" Algorithm="FIPS140_INTEGRITY">MC0CFDoz1S5pB5Xh05VEtv3AbkMPK4CkAhUAmw7QALTE0DLz2RAYR9U/WPdvCCM=</Signature>
	<Signature URI="#ccme_base_non_fips" Algorithm="FIPS140_INTEGRITY">MC0CFQCtFnMUSGnolS9hIn19j6yozhoKDQIUFko+KvvVuzBGiHerYvdCs1KM1DA=</Signature>
	<Signature URI="#ccme_asym" Algorithm="FIPS140_INTEGRITY">MC4CFQCPR2eXJt18sZlAjktAy4gnf/oN2AIVALrCXT5ZSl4aL4rVK+aYZGLtP29H</Signature>
	<Signature URI="#ccme_ecc" Algorithm="FIPS140_INTEGRITY">MC0CFQCfly9XksBQ22cCGzGnAeLy0tz0zAIUZYGWiCeCUSdMT0u6KeXmpq/9AYs=</Signature>
	<Signature URI="#ccme_ecc_non_fips" Algorithm="FIPS140_INTEGRITY">MC0CFQDFsHwMzuIOBpV+PVYnrVRXCoW45AIUVxlUueNHg/9OcyYB+lCV3Ba/EGk=</Signature>
	<Signature URI="#ccme_ecdrbg" Algorithm="FIPS140_INTEGRITY">MCwCFAi7up9d6EgCj8+AXHr3oTzCwbeNAhRBlPgZY9y14284dxrfjM/DkFsG6w==</Signature>
	<Signature URI="#ccme_ecc_accel_fips" Algorithm="FIPS140_INTEGRITY">MC0CFBove4VcaqqnshqdVbgGQnjYGCz8AhUAjkxju4jj2MthKhh25GLm7p+hVJo=</Signature>
	<Signature URI="#ccme_ecc_accel_non_fips" Algorithm="FIPS140_INTEGRITY">MC0CFQCL7eolCxarGaFWA1f2fbUJvSAsywIUdYMcejuufWeqwIioH2g9J0OYagI=</Signature>
	<Signature URI="#ccme_error_info" Algorithm="FIPS140_INTEGRITY">MC0CFQChe556vaaqaJ33UJOxWors8mtZ1wIUDjPdyMSWzC0RhmJdriekF16K96c=</Signature>
	<Signature URI="#master" Algorithm="FIPS140_INTEGRITY">MCwCFGWyrq29TfLWCXcMBgj5NRlVWCW7AhRjZ7TVAE1f0KHx2VCe7K8y3wZlBg==</Signature>
	<Signature URI="#Crypto-C ME" Algorithm="FIPS140_INTEGRITY">MC0CFBMiXTtPGx5iPjSxJ7ahqKONBs9DAhUApV06vJp6sjqddTBkDytCVoVcQb0=</Signature>
	<Signature URI="#runtime" Algorithm="FIPS140_INTEGRITY">MC4CFQC001oxR1uT0/XJ5T9+W8LSB/wsMwIVAL62EZ63xsHipOR+mWVOD09vvaDv</Signature>
</Configuration>

