plugins {
    id("java")
    id("com.github.johnrengelman.shadow") version "8.1.1"
    //id("io.github.file5.guidesigner") version "1.0.2"
}

group = "jp.ac.ait.k23023"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

dependencies {
    implementation("com.intellij:forms_rt:7.0.3")
    implementation("com.google.code.gson:gson:2.11.0")
    testImplementation(platform("org.junit:junit-bom:5.10.0"))
    testImplementation("org.junit.jupiter:junit-jupiter")
}

tasks.test {
    useJUnitPlatform()
}
tasks.jar{
    manifest {
        attributes["Main-Class"] = "jp.ac.ait.k23023.AddressBook"
    }

}