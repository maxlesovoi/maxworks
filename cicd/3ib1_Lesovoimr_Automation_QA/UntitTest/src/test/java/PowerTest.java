import org.example.Main;
import org.example.Power;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.extension.ExtensionContext;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.ArgumentsProvider;
import org.junit.jupiter.params.provider.ArgumentsSource;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

public class PowerTest {

    @ParameterizedTest
    @ArgumentsSource(PowTestArgs.class)
    void Test(int a, int b, int result) {

        Assertions.assertEquals(Power.pow(a, b), result);

    }


    static class PowTestArgs implements ArgumentsProvider {
        @Override
        public Stream<? extends Arguments> provideArguments(ExtensionContext context) throws SQLException {
            List<Arguments> teststream = new ArrayList<>();
            String url = "jdbc:postgresql://localhost:5432/power";
            String user = "postgres";
            String password = "1";
            Connection connection = DriverManager.getConnection(url, user, password);

            ResultSet resultSet = connection.createStatement().executeQuery("SELECT * FROM data");
            while (resultSet.next()){
                teststream.add(Arguments.of(resultSet.getInt("a"),resultSet.getInt("b"),resultSet.getInt("result")));
            }
            return teststream.stream();
        }
    }
}
