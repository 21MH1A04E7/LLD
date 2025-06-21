// Interface-like abstraction
class IReports {
    getJsonData(data) {
        throw new Error("Method not implemented");
    }
}

// Adaptee: provides XML data
class XmlDataProvider {
    getXmlData(data) {
        const [name, id] = data.split(":");
        return `<user><name>${name}</name><id>${id}</id></user>`;
    }
}

// Adapter: converts XML to JSON
class XmlDataProviderAdapter extends IReports {
    constructor(provider) {
        super();
        this.xmlProvider = provider;
    }

    getJsonData(data) {
        const xml = this.xmlProvider.getXmlData(data);

        const name = xml.match(/<name>(.*?)<\/name>/)[1];
        const id = xml.match(/<id>(.*?)<\/id>/)[1];

        return JSON.stringify({ name, id: parseInt(id) });
    }
}

// Client
class Client {
    getReport(report, rawData) {
        console.log("Processed JSON:", report.getJsonData(rawData));
    }
}

// Usage
const xmlProvider = new XmlDataProvider();
const adapter = new XmlDataProviderAdapter(xmlProvider);
const client = new Client();

const rawData = "Alice:42";
client.getReport(adapter, rawData);
